//
// Created by hubert on 09.04.19.
//

#include "Functions.h"

double Interpolation (double *knot_vector, double *function_value, int lvl, double x_value)
{
	double result = 0.0;
	double nominator;
	double denominator;

	for (int i = 0; i < lvl + 1; i++)
	{
		 nominator = 1.0;
		 denominator = 1.0;
		for (int j = 0; j < lvl + 1; j++)
		{
			if (i == j)
				continue;
			nominator *= (x_value - knot_vector[j]);
		}

		for (int j = 0; j < lvl + 1; j++)
		{
			if (i == j)
				continue;
			denominator *= (knot_vector[i] - knot_vector[j]);
		}
		result += function_value[i] * (nominator / denominator);
	}

	return result;
}

void Fill_exp (const double *args, double *function_values, int N)
{
	for (int i = 0; i < N; i++)
	{
		function_values[i] = exp (-pow (args[i], 2));
	}
}
