#pragma once
// #include "/opt/NR/numerical_recipes.c/nrutil.h"
// #include "/opt/NR/numerical_recipes.c/nrutil.c"
// #include "/opt/NR/numerical_recipes.c/tred2.c"
// #include "/opt/NR/numerical_recipes.c/tqli.c"
// #include "/opt/NR/numerical_recipes.c/pythag.c"
#include "/home/hubert/Numerical_recipes/pythag.cpp"
#include "/home/hubert/Numerical_recipes/tqli.cpp"
#include "/home/hubert/Numerical_recipes/tred2.cpp"
#include "/home/hubert/Numerical_recipes/nrutil.cpp"
#include "/home/hubert/Numerical_recipes/nrutil.h"



const int nx = 20;
const int ny = 20;
const int n = nx * ny;
const int m = 10;
const float t = -0.021;

void intialiaze_matrix_null(float ***matrix);
void intialiaze_vector_null(float **vector);
void intialiaze_main_matrix(float ***matrix);
void pomnoz(float **A, float **B, float ***C);
void sort(float **d, int **index);
void file_print(float **X, int *index, FILE *fp);
void intialiaze_Y_matrix(float ***matrix);