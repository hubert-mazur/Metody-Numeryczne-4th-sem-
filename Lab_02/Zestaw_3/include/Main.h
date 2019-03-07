#pragma once
# include "/opt/NR/numerical_recipes.c/nrutil.h"
# include "/opt/NR/numerical_recipes.c/nrutil.c" 
# include "/opt/NR/numerical_recipes.c/ludcmp.c"
#define N 400
#define b 2
#define a 0.5
#include <stdio.h>
#include <stdlib.h>
void inicjalizuj_macierz(float ***A);
void inicjalizuj_0(float ***A);
void inicjalizuj_L_U(float ***L, float ***U, float **A);
void pomnoz(float **A, float **B, float ***C);
float wyznacznik(float **A);
void d_inicjalizuj_wektor(int **A);
float max_value(float **A);
void rozwiaz_wektor(float **A, int *invector, float **free_memb, int iteracja);
void zeruj_vect(float **vec);
void inicjalizuj_spec(float ***A);
void wypisz(float **arr);
void inicjalizuj_wektor_wyrazow_wolnych(float **b_vector);
void inicjalizuj_y_wektor(float **y_vector, float *b_vector, float **L);
void inicjalizuj_v_vector(float **v_vector, float *y_vector, float **U);
void inicjalizuj_wektor_wartosci_rzeczywistych(float **tr_vector);
float *b_vector;
int *invector;
float **A;
const float h = (((2.0 * b) / (N - 1.0)));
float d;
float **L;
float **U;
float *y_vector;
float *v_vector;
float *tr_vector;
FILE *file_ptr_NR;
FILE *file_ptr_TR;
