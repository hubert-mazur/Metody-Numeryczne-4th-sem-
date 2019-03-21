#pragma once
#include "/home/hubert/gsl/include/gsl/gsl_eigen.h"
#include "/home/hubert/gsl/include/gsl/gsl_matrix.h"
#include <math.h>
#include <stdio.h>
const int L = 10;
const int n = 200;
const int N = 1;

void init_matrix(gsl_matrix *A);
void init_A(gsl_matrix **A);
void init_B(gsl_matrix **A,int alfa);
int cronecker(int i, int j);
float p_function (int alfa, int i);
