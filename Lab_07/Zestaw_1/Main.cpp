//
// Created by hubert on 09.04.19.
//

#include "Functions.h"

int main ()
{
	const int N = 20;
	auto *knots = new double[N];
	auto *function_values = new double[N];
	auto *interpolation = new double[100];
	int left = -5;
	int right = 5;

	knots[0] = left;
	knots[N - 1] = right;


//	double step = (abs (left) + abs (right)) / static_cast<double>((N - 1));
//	for (int i = 1; i <= N - 2; i++) // zwykle wyznaczanie polozenia wezlow
//		knots[i] = left + (step * i);

	for (int i = 1; i < N - 2; i++)
	{
		knots[i] = 0.5*((right-left)*(cos(M_PI*((double)((2*i)+1)/((2*N)+1)))+(left+right))); // optymalizacja polozenia wezlow
	}


	Fill_exp (knots, function_values, N);

	double temp = -5;

	for (int i = 0; i < 100; i++)
	{
		interpolation[i] = Interpolation (knots, function_values, N - 1, temp);
		temp += 0.1;
	}

	FILE *fp = fopen ("dane_op4.dat", "w");
	if (!fp)
		exit (-1);

	temp = -5;

	for (int i = 0; i < 100; i++)
	{
		fprintf (fp, "%7g %7g %7g\n", temp, exp (-pow (temp, 2)), interpolation[i]);
		temp += 0.1;
	}

	delete[] knots;
	delete[] function_values;
	delete[] interpolation;
	fclose (fp);
}



