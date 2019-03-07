#ifndef _DEFS_H_
#define _DEFS_H_
#include "/home/hubert/Numerical_recipes/nrutil.cpp"
#include "/home/hubert/Numerical_recipes/nrutil.h"
#include "/home/hubert/Numerical_recipes/ludcmp.c"
//# include "/opt/NR/numerical_recipes.c/nrutil.h"
//# include "/opt/NR/numerical_recipes.c/nrutil.c" // na taurusie trzeba kompilowac z tymi bibliotekami!
//# include "/opt/NR/numerical_recipes.c/ludcmp.c"
#define N 4
float **A;
void inicjalizuj_macierz(float ***A);
void inicjalizuj_0(float ***A);
void inicjalizuj_U(float ***U, float **A);
void inicjalizuj_L(float ***L, float **A);
void pomnoz(float **A, float **B, float ***C);
float wyznacznik(float **A);
void d_inicjalizuj_wektor(int **A);
float max_value(float **A);
void rozwiaz_wektor(float **A, int *invector, float **free_memb, int iteracja);
void zeruj_vect(float **vec);
float *free_member;
float d;
int *A_invector;
float **L_A;
float **U_A;
float **A_rev;
float **A_jednostkowa;
FILE *file_ptr;
#endif
