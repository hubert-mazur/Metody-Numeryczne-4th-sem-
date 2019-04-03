//
// Created by hubert on 26.03.19.
//

#ifndef LAB_05_MAIN_H
#define LAB_05_MAIN_H

#include <iostream>
#include <stdio.h>
#include <math.h>

//// include files ////

#include "/home/hubert/Numerical_recipes/nrutil.h"
#include "/home/hubert/Numerical_recipes/nrutil.cpp"
#include "/home/hubert/Numerical_recipes/tred2.cpp"
#include "/home/hubert/Numerical_recipes/tqli.cpp"
#include "/home/hubert/Numerical_recipes/pythag.cpp"
// #include "/opt/NR/numerical_recipes.c/nrutil.h"
// #include "/opt/NR/numerical_recipes.c/nrutil.c"
// #include "/opt/NR/numerical_recipes.c/tred2.c"
// #include "/opt/NR/numerical_recipes.c/tqli.c"
// #include "/opt/NR/numerical_recipes.c/pythag.c"

//// global variables ////

const int N = 7;

//// functions ////

void intialiaze_matrix(float ***matrix);
void intialiaze_I_0_matrix(float ***matrix);
void intialiaze_0_vector(float **vector);
void Copy_matrix(float ***copy_to_matrix, float **copy_from_matrix);
void matrix_vector(float **matrix, float *_vector, float **result_vector);
void copy_vector(float **copy_to_vect, float *copy_from_vect);      
void mnoz(float *tab1, float *tab2, float ***tab3, int x, int middle, int y);
void const_multi_matrix (float consts, float ***matrix);
void subtract_matrix_matrix (float **matrix1,float **matrix2,float ***matrix3);
float vector_dot_vector (float *vect1,float *vect2);
float vector_norm(float *vector);

#endif //LAB_05_MAIN_H
