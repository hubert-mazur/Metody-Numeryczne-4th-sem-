//
// Created by hubert on 09.04.19.
//
#include "Functions.h"

int main ()
{

	int N = 7;
	auto *function_values = new double[N];
	auto *knots = new double[N];
	double **differ_quotient;

	knots[0] = -5;
	knots[1] = -2;
	knots[2] = -0.5;
	knots[3] = 0;
	knots[4] = 0.5;
	knots[5] = 2;
	knots[6] = 5;


	differ_quotient = new double *[N];
	fill_function_values (knots, function_values, N);

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


	for (double i = -1; i < 1.001; i += 0.01)
	{
		fprintf (fp, "%lf %lf %lf\n", i, 1.0 / (1.0 + pow (i, 2)), interpolate (knots, differ_quotient, N, i));
	}



// free

	for (int i = 0; i < N; i++)
		delete[] differ_quotient[i];

	delete[] differ_quotient;
	delete[] knots;
	delete[] function_values;
	fclose (fp);
	return 0;
}