//
// Created by hubert on 09.04.19.
//

#include "Functions.h"

void fill_function_values (const double *args, double *values, int N)
{
	for (int i = 0; i < N; i++)
		values[i] = 1.0 / (1 + pow (args[i], 2));
}

void difference_quotient (const double *args, const double *values, double ***result, int N)
{
	int xi = N - 1;
	for (int j = 2; j < N + 2; j++)
	{
		for (int i = 0; i < xi; i++)
			(*result)[i][j] =
					((*result)[i + 1][j - 1] - (*result)[i][j - 1]) / ((*result)[i + j - 1][0] - (*result)[i][0]);
		xi--;
	}


	for (int i = 0; i < N-1 ; i++)
	{
		for (int j=2;j<N+2;j++)
			std::cout << (*result)[i][j] << " ";
		std::cout << std::endl;
	}

}

double interpolate (double *args, double **difference_arr, int N, double value)
{
	double sum = 0;

	// sum = (1.0 / (1 + pow (args[0], 2))) + (difference_arr[0][2] * (value - args[0])) +
	// 	  difference_arr[0][3] * (value - args[0]) * (value - args[1]) +
	// 	  (difference_arr[0][4] * (value - args[0]) * (value - args[1]) * (value - args[2])) +
	// 	  (difference_arr[0][5] * (value - args[0]) * (value - args[1]) * (value - args[2]) * (value - args[3])) +
	// 	  (difference_arr[0][6] * (value - args[0]) * (value - args[1]) * (value - args[2]) * (value - args[3]) *
	// 	   (value - args[4])) +
	// 	  (difference_arr[0][7] * (value - args[0]) * (value - args[1]) * (value - args[2]) * (value - args[3]) *
	// 	   (value - args[4]) * (value - args[5])) +
	// 	  (difference_arr[0][8] * (value - args[0]) * (value - args[1]) * (value - args[2]) * (value - args[3]) *
	// 	   (value - args[4]) * (value - args[5]) * (value - args[6]));

	double temp;

	sum += (1.0 / (1 + pow (args[0], 2)));

	for (int i=1;i<N;i++)
	{
		temp = 1;
		for (int j=0;j<i;j++)
		{
			
			temp*= (value-args[j]);
		}
		temp *= difference_arr[0][i+1];
		sum += temp; 
	}

	return sum;
}
