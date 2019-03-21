#pragma once

#include "/home/hubert/gsl/include/gsl/gsl_eigen.h"
#include "/home/hubert/gsl/include/gsl/gsl_complex.h"
#include "/home/hubert/gsl/include/gsl/gsl_complex_math.h"
#include "/home/hubert/gsl/include/gsl/gsl_vector.h"
#include "math.h"
#include <iostream>

void init_matrix(gsl_matrix *matrix, int alfa);
int cronecker(int i, int j);
float p_function(int alfa, int i);
void print_matrix(gsl_matrix *A);

double L = 10.0, N = 1.0;
int i, j, k, alfa = 0, n = 200;

const double delta_x = L / (n + 1);
double x_i, p_i;
