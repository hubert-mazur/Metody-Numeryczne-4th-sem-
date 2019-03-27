//
// Created by hubert on 26.03.19.
//

#include "Main.h"

void intialiaze_matrix(float ***matrix)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			(*matrix)[i][j] = sqrt(i + j);
		}
	}
}

void intialiaze_I_0_matrix(float ***matrix)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			(*matrix)[i][j] = (i == j);
		}
	}
}

void intialiaze_0_vector(float **vector)
{
	for (int i = 1; i <= N; i++)
		(*vector)[i] = 1;
}

void Copy_matrix(float ***copy_to_matrix, float **copy_from_matrix)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			(*copy_to_matrix)[i][j] = copy_from_matrix[i][j];
		}
	}
}

void matrix_vector(float **matrix, float *_vector, float **result_vector)
{
	float suma;
	for (int i = 1; i <= N; i++)
	{
		suma = 0;
		for (int j = 1; j <= N; j++)
		{
			suma += matrix[i][j] * _vector[j];
		}
		(*result_vector)[i] = suma;
	}
}

float vector_dot_vector(float *vect1, float *vect2)
{
	float suma = 0;

	for (int i = 1; i <= N; i++)
	{
		suma += vect1[i] * vect2[i];
	}

	return suma;
}

float vector_norm(float *vector)
{
	float suma = 0;

	for (int i = 1; i <= N; i++)
	{
		suma += vector[i] * vector[i];
	}
	return sqrt(suma);
}

void copy_vector(float **copy_to_vect, float *copy_from_vect)
{
	for (int i = 1; i <= N; i++)
	{
		(*copy_to_vect)[i] = copy_from_vect[i];
	}
}

void divide_vector(float **vect, float value)
{
	for (int i = 1; i <= N; i++)
	{
		(*vect)[i] /= value;
	}
}

void mnoz(float *tab1, float *tab2, float ***tab3, int x, int middle, int y)
{
	float suma;
	for (int i = 1; i <= x; i++)
	{
		suma = 0;
		for (int j = 1; j <= y; j++)
		{

			for (int k = 1; k <= middle; k++)
			{
				suma += ((*(tab1 + i))) * ((*(tab2 + k)));
			}
			(*tab3)[i][j] = suma;
		}
	}
}

void const_multi_matrix(float consts, float ***matrix)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			(*matrix)[i][j] *= consts;
		}
	}

	// for (int i=1;i<=N;i++)
	// {
	// 	for (int j=1;j<=N;j++)
	// 	std::cout<<(*matrix)[i][j]<<" ";
	// 	std::cout<<std::endl;
	// }
}

void subtract_matrix_matrix(float **matrix1, float **matrix2, float ***matrix3)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			(*matrix3)[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}

	// for (int i=1;i<=N;i++)
	// {
	// 	for (int j=1;j<=N;j++)
	// 	std::cout<<matrix2[i][j]<<" ";
	// 	std::cout<<std::endl;
	// }
}
