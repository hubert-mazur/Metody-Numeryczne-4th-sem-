#include "Main.h"
#include "Functions.cpp"
int main()
{

	//// initialization ////

	float **A_matrix;
	float **Z_matrix;
	float **W_matrix;
	float **temp_matrix;

	float *d_vector;
	float *e_vector;
	float *x_0_vector;
	float *start_vector;

	FILE *file_ptr;

	//// alloc memory ////

	A_matrix = matrix(1, N, 1, N);
	Z_matrix = matrix(1, N, 1, N);
	W_matrix = matrix(1, N, 1, N);
	temp_matrix = matrix(1, N, 1, N);

	d_vector = vector(1, N);
	e_vector = vector(1, N);
	x_0_vector = vector(1, N);
	start_vector = vector(1, N);

	file_ptr = fopen("dane.dat", "w");
	if (!file_ptr)
	{
		std::cout << "ERR while opening file! Leaving...\n";
		return -1;
	}

	//// main ////

	int k = 1;
	float lambda;

	intialiaze_matrix(&A_matrix);
	intialiaze_I_0_matrix(&Z_matrix);

	Copy_matrix(&W_matrix, A_matrix);

	tred2(A_matrix, N, d_vector, e_vector);
	tqli(d_vector, e_vector, N, Z_matrix);
	
	fprintf(file_ptr,"Wartosci wlasne: \n");

	for (int i = 1; i <= N; i++)
		fprintf(file_ptr, "%f ", d_vector[i]);

	fprintf(file_ptr, "\n");
	fprintf(file_ptr, "\n");

intialiaze_0_vector(&start_vector);

	while (k <= N)
	{
		fprintf(file_ptr,"przblizenia wartosci wlasnej dla: k = %d,  wartosc wlasna ---> %5g\n",k,d_vector[8-k]);
		for (int i = 0; i < 8; i++)
		{
			matrix_vector(W_matrix, start_vector, &x_0_vector);
			lambda = (vector_dot_vector(x_0_vector, start_vector) / vector_dot_vector(start_vector, start_vector));
			divide_vector(&x_0_vector, (vector_norm(x_0_vector)));
			copy_vector(&start_vector, x_0_vector);
			
			fprintf(file_ptr, "l%d =  %5g \n",i+1, lambda);
		}

		fprintf(file_ptr, "\n\n");

		mnoz(start_vector, start_vector, &temp_matrix, N, 1, N);
		const_multi_matrix(lambda, &temp_matrix);
		subtract_matrix_matrix(W_matrix, temp_matrix, &Z_matrix);
		Copy_matrix(&W_matrix, Z_matrix);

		k++;
	}

	//// free memory ////

	free_matrix(A_matrix, 1, N, 1, N);
	free_matrix(Z_matrix, 1, N, 1, N);
	free_matrix(W_matrix, 1, N, 1, N);
	free_matrix(temp_matrix, 1, N, 1, N);

	free_vector(d_vector, 1, N);
	free_vector(e_vector, 1, N);
	free_vector(x_0_vector, 1, N);
	free_vector(start_vector, 1, N);

	fclose(file_ptr);

	return 0;
}