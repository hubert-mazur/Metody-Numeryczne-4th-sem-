//
// Created by hubert on 09.04.19.
//
#include "Functions.h"

int main ()
{

	int N = 7;
	double *function_values;
	double *knots;
	double **differ_quotient;


		knots = new double [N];
		function_values = new double [N];

		knots[0] = -5;
//	 knots[1] = -2;
//	 knots[2] = -0.5;
//	 knots[3] = 0;
//	 knots[4] = 0.5;
//	 knots[5] = 2;
		knots[N-1] = 5;

		double step = (abs (-5) + abs (5)) / static_cast<double>((N - 1));
		for (int i = 1; i <= N - 2; i++) // dla wezlow rownoodleglych
		{
			knots[i] = -5 + (step * i);
//			std::cout << knots[i] << " ";
		}
//		std::cout << std::endl << std::endl;


<<<<<<< HEAD
	for (int i = 0; i < N; i++)
	{
		differ_quotient[i] = new dou7mazur@stud205-14:~/Metody_numeryczne/Metody-Numeryczne-4th-sem-/Lab_07/Zestaw_2$ gnuplot gnuplot.sh 
le[N + 2];
	}
=======
		differ_quotient = new double *[N];
		fill_function_values (knots, function_values, N);
>>>>>>> a5f969dd22b7477de283766c34a11c783cc0ae90

		for (int i = 0; i < N; i++)
		{
			differ_quotient[i] = new double[N + 2];
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N + 2; j++)
				differ_quotient[i][j] = 0;
		}

		for (int i = 0; i < N; i++)
		{
			differ_quotient[i][0] = knots[i];
			differ_quotient[i][1] = function_values[i];
		}

		difference_quotient (knots, function_values, &differ_quotient, N);

		FILE *fp;
		fp = fopen ("dane.dat", "w");

		if (!fp)
			exit (-2);

		double temp = 0;
		for (double i = -5; i < 5.001; i += 0.01)
		{
			fprintf (fp, "%lf %lf %lf\n", i, 1.0 / (1.0 + pow (i, 2)), interpolate (knots, differ_quotient, N, i));

		}


// free

	for (int i = 0; i < N; i++)
		delete[] differ_quotient[i];

	delete[] differ_quotient;
	delete[] knots;
	delete[] function_values;
//	fclose (fp);
	return 0;
}