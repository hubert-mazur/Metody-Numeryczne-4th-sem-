#pragma once

// headers //
#include "/home/hubert/Numerical_recipes/nrutil.h"
#include "/home/hubert/Numerical_recipes/nrutil.cpp"
#include "/home/hubert/Numerical_recipes/tred2.cpp"
#include "/home/hubert/Numerical_recipes/tqli.cpp"
#include "/home/hubert/Numerical_recipes/pythag.cpp"
#include <stdio.h>
#include <math.h>
#include <vector>
// const values //

const int n = 5;

// functions headers //

void intialiaze_matrix(float ***matrix);
void intialiaze_matrix_I_0(float ***I_0_matrix);
float get_beta(float **matrix_A, float **matrix_Y, int column);
float multiply_vector_vector(float *vect1, float *vect2);
void multiply_matrices(float **A, float **B, float ***C);