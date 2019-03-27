#pragma once

//// include

#include "/home/hubert/gsl/include/gsl/gsl_matrix.h"
#include <math.h>
#include <stdio.h>
//// global variables ////

const int N = 7;
const int IT_MAX = 12; // max number of iterations

//// functions headers ////

void intialiaze_matrix(gsl_matrix **A_matrix);
void copy_matrix(gsl_matrix **W_matrix, gsl_matrix *A_matrix);
void iniialiaze_start_vector(gsl_vector **start_vector);
void multiply_matrix_vector(gsl_matrix *matrix, gsl_vector *vector, gsl_vector **result_vector);
void copy_normed_vector(gsl_vector **start_vector, gsl_vector *x_vector);
void substract_matrices(gsl_matrix *W_matrix, gsl_matrix *temp_matrix, gsl_matrix **W_matrix_result);
void multiply_vector_vector_to_matrix(gsl_vector *start_vect1, gsl_vector *start_vect2, gsl_matrix **temp_matrix);
void multiply_matrix_const(float cons, gsl_matrix **temp_matrix);
void matrix_multiplier(gsl_matrix *matrix1, gsl_matrix *matrix2, gsl_matrix **matrix3);
float multiply_vector_vector(gsl_vector *vector1, gsl_vector *vector2);
float norm_vector(gsl_vector *vector);
void transpose_matrix(gsl_matrix **matrix);
