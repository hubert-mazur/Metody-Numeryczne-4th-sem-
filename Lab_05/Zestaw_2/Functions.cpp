#include "Main.h"

void intialiaze_matrix(gsl_matrix **A_matrix)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            gsl_matrix_set(*A_matrix, i, j, (1.0 / (sqrt(2 + abs(i - j)))));
        }
    }
}

void copy_matrix(gsl_matrix **W_matrix, gsl_matrix *A_matrix)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            gsl_matrix_set(*W_matrix, i, j, gsl_matrix_get(A_matrix, i, j));
        }
    }
}

void iniialiaze_start_vector(gsl_vector **start_vector)
{
    for (int i = 0; i < N; i++)
        gsl_vector_set(*start_vector, i, 1);
}

void multiply_matrix_vector(gsl_matrix *matrix, gsl_vector *vector, gsl_vector **result_vector)
{
    float suma;

    for (int i = 0; i < N; i++)
    {
        suma = 0;
        for (int j = 0; j < N; j++)
        {
            suma += gsl_matrix_get(matrix, i, j) * gsl_vector_get(vector, j);
        }
        gsl_vector_set(*result_vector, i, suma);
    }
}

float multiply_vector_vector(gsl_vector *vector1, gsl_vector *vector2)
{
    float suma = 0;

    for (int i = 0; i < N; i++)
        suma += gsl_vector_get(vector1, i) * gsl_vector_get(vector2, i);

    return suma;
}

float norm_vector(gsl_vector *vector)
{
    float suma = 0;
    for (int i = 0; i < N; i++)
    {
        suma += gsl_vector_get(vector, i) * gsl_vector_get(vector, i);
    }
    return sqrt(suma);
}

void copy_normed_vector(gsl_vector **start_vector, gsl_vector *x_vector)
{
    float vect_norm = norm_vector(x_vector);
    for (int i = 0; i < N; i++)
    {
        gsl_vector_set(*start_vector, i, gsl_vector_get(x_vector, i) / vect_norm);
    }
}

void multiply_vector_vector_to_matrix(gsl_vector *start_vect1, gsl_vector *start_vect2, gsl_matrix **temp_matrix)
{
    float suma;
    for (int i = 0; i < N; i++)
    {
        suma = 0;
        for (int j = 0; j < N; j++)
        {

            for (int k = 0; k < 1; k++)
            {
                suma += gsl_vector_get(start_vect1, i) * gsl_vector_get(start_vect2, k);
            }
            gsl_matrix_set(*temp_matrix, i, j, suma);
        }
    }
}

void multiply_matrix_const(float cons, gsl_matrix **temp_matrix)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            gsl_matrix_set(*temp_matrix, i, j, gsl_matrix_get(*temp_matrix, i, j) * cons);
        }
    }
}

void substract_matrices(gsl_matrix *W_matrix, gsl_matrix *temp_matrix, gsl_matrix **W_matrix_result)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            gsl_matrix_set(*W_matrix_result, i, j, gsl_matrix_get(W_matrix, i, j) - gsl_matrix_get(temp_matrix, i, j));
        }
    }
}

void matrix_multiplier(gsl_matrix *matrix1, gsl_matrix *matrix2, gsl_matrix **matrix3)
{
    float suma;

    for (int i = 0; i < N; i++)
    {
        suma = 0;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                suma += gsl_matrix_get(matrix1, i, k) * gsl_matrix_get(matrix2, k, j);
            }
            gsl_matrix_set(*matrix3, i, j, suma);
        }
    }
}

void transpose_matrix(gsl_matrix **matrix)
{
    double temp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            temp = gsl_matrix_get(*matrix, i, j);
            gsl_matrix_set(*matrix, i, j, gsl_matrix_get(*matrix, j, i));
            gsl_matrix_set(*matrix, j, i, temp);
        }
    }
}