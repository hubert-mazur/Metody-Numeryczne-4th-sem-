# include <iostream>
# include "gsl/gsl_math.h"
# include "gsl/gsl_linalg.h"
# include <stdio.h>
# include <stdlib.h>
# define N 4
void set_values (gsl_matrix **A);
void wypisz (gsl_matrix *A);
void pomnoz( gsl_matrix *A, gsl_matrix *B, gsl_matrix *C);
float max_value(gsl_matrix **A);
int main (void)
{
	gsl_matrix *A = gsl_matrix_calloc (N,N);
	gsl_matrix *A_inv = gsl_matrix_calloc (N,N);
	set_values(&A);
	wypisz (A);
	gsl_permutation * vector=gsl_permutation_calloc(N);
	int signum;
	gsl_linalg_LU_decomp(A,vector,&signum);
	FILE *file_ptr;
	file_ptr=fopen ("out.dat","w");
	if (!file_ptr)
	return -1;
	fprintf(file_ptr,"Elementy diagonalne: \n");
	float wyznacznik=1;
	for (int i=0;i<N;i++)
	{
		wyznacznik*=gsl_matrix_get(A,i,i);
		fprintf(file_ptr,"   %g   ",gsl_matrix_get(A,i,i));
		fprintf (file_ptr,"\n");
	}
	fprintf (file_ptr,"wyznacznik :  %g  \n",wyznacznik);

	gsl_vector *b = gsl_vector_calloc(N);
	gsl_vector *x = gsl_vector_calloc(N);
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		gsl_vector_set(b,j,0);

		gsl_vector_set(b,i,1);
		gsl_linalg_LU_solve (A,vector,b,x);
		for (int j=0;j<N;j++)
		{
			gsl_matrix_set(A_inv,j,i,gsl_vector_get(x,j));
		}
	}
	fprintf (file_ptr,"\nMacierz odwrotna: \n");

	wypisz (A_inv);

	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		{
			fprintf (file_ptr,"   %3g   ",gsl_matrix_get(A_inv,i,j));
		}
		fprintf (file_ptr,"\n");
	}

gsl_matrix *macierz_jednostkowa =gsl_matrix_calloc (N,N);
printf ("macierz jednostkowa\n");
set_values (&A);
pomnoz(A,A_inv,macierz_jednostkowa);
wypisz (macierz_jednostkowa);




	fprintf (file_ptr,"\nMacierz jednostkowa: \n");

	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		{
			fprintf (file_ptr,"   %3g   ",gsl_matrix_get(macierz_jednostkowa,i,j));
		}
		fprintf (file_ptr,"\n");
	}

	float wspolczynnik=0;
	wspolczynnik=max_value(&A)*max_value(&A_inv);
		printf ("wspolczynnik uwarunkowania : %f\n",wspolczynnik);
	fprintf (file_ptr,"wspolczynnik uwarunkowania : %f\n",wspolczynnik);


	gsl_matrix_free (A);
	gsl_matrix_free(A_inv);
	gsl_permutation_free (vector);
	gsl_matrix_free (macierz_jednostkowa);
	gsl_vector_free (b);
	gsl_vector_free (x);
	fclose (file_ptr);


}
void set_values (gsl_matrix **A)
{
	double delta=2.0;
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		{
			gsl_matrix_set (*A,i,j,(1.0/(float)(i+j+delta)));
		}
	}
}
void wypisz (gsl_matrix *A)
{
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		{
			printf("   %3f   ",gsl_matrix_get(A,i,j));
		}
		printf ("\n");
	}
}
void pomnoz(gsl_matrix *A, gsl_matrix *B, gsl_matrix *C)
{
    float suma;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            suma = 0;
            for (int k = 0; k < N; k++)
            {
                suma += gsl_matrix_get(A,i,k) * gsl_matrix_get(B,k,j);
            }
			gsl_matrix_set(C,i,j,suma);
        }
    }

}
	float max_value(gsl_matrix **A)
{
    float max = abs(gsl_matrix_get(*A,0,0));
    for (int i =0 ; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (abs(gsl_matrix_get(*A,i,j)) > max)
            {
                max = gsl_matrix_get(*A,i,j);
            }
        }
    }
    return max;
}