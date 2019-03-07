#ifndef _DEFS_H_
#define _DEFS_H_
#include <iostream>
#include "/home/hubert/Numerical_recipes/nrutil.cpp"
#include "/home/hubert/Numerical_recipes/nrutil.h"
#include "/home/hubert/Numerical_recipes/ludcmp.c"
//# include "/opt/NR/numerical_recipes.c/nrutil.h"
//# include "/opt/NR/numerical_recipes.c/nrutil.c" // na taurusie trzeba kompilowac z tymi bibliotekami!
//# include "/opt/NR/numerical_recipes.c/ludcmp.c"
#include <stdio.h>
#define N 3
void wypisz(float **);
void inicjalizuj_spec(float ***A);
void inicjalizuj_0(float ***A);
void f_inicjalizuj_wektor(float **A);
void d_inicjalizuj_wektor(int **A);
void rozwiaz_wektor(float **A, int *invector, float **free_memb, int iteracja);
void pomnoz(float **A, float **B, float ***C);
void inicjalizuj_L(float ***L, float **A);
void inicjalizuj_U(float ***U, float **A);
void zeruj_vect(float **vec);
float max_value(float **A);
float **A, **B;
int *A_invector;
int *B_invector;
float d = 1.0;
float **L_A, **L_B, **U_A, **U_B;
float **tempr_A;
float **tempr_B;
float **A_rev;
float **B_rev;
float *free_member;
float *temp = NULL;
float **A_jednostkowa;
float **B_jednostkowa;
#endif
