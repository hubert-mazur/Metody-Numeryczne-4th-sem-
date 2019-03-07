#include "defs.h"
#include <iostream>
#include <stdio.h>

int main(void)
{
    A = matrix(1, N, 1, N);
    inicjalizuj_macierz(&A);
    d_inicjalizuj_wektor(&A_invector);
    ludcmp(A, N, A_invector, &d);
    inicjalizuj_U(&U_A, A);
    inicjalizuj_L(&L_A, A);
    file_ptr = fopen("out.dat", "w");
    if (!file_ptr)
    {
        std::cout << "\nERR  while opening file! LEAVING...\n";
        return -1;
    }
    fprintf(file_ptr, "\nDiagonalia macierzy U: \n");
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                fprintf(file_ptr, " %f ", U_A[i][j]);
            else
            {
                fprintf(file_ptr, " %3s", "  ");
            }
        }
        fprintf(file_ptr, "\n");
    }
    fprintf(file_ptr, "\nWyznacznik macierzy: %f\n", wyznacznik(A));
    free_member = vector(1, N);
    zeruj_vect(&free_member);
    A_rev = matrix(1, N, 1, N);
    inicjalizuj_0(&A_rev);
    for (int i = 1; i <= N; i++)
    {
        rozwiaz_wektor(A, A_invector, &free_member, i);
        for (int j = 1; j <= N; j++)
            A_rev[j][i] = free_member[j];
        zeruj_vect(&free_member);
    }
    fprintf(file_ptr, "\nMacierz odwrotna: \n");
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            fprintf(file_ptr, "   %3f   ", A_rev[i][j]);
        fprintf(file_ptr, "\n");
    }

    A_jednostkowa = matrix(1, N, 1, N);
    inicjalizuj_0(&A_jednostkowa);
    inicjalizuj_macierz(&A);
    pomnoz(A, A_rev, &A_jednostkowa);

    fprintf(file_ptr, "\nMacierz jednostkowa? \n");
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            fprintf(file_ptr, "   %3f   ", A_jednostkowa[i][j]);
        fprintf(file_ptr, "\n");
    }
    fprintf(file_ptr, "Wskaznik uwarunkowania macierzy A: %3f  ", max_value(A) * max_value(A_rev));
    free_matrix(A, 1, N, 1, N);
    free_matrix(A_rev, 1, N, 1, N);
    free_vector(free_member, 1, N);
    free_ivector(A_invector, 1, N);
    free_matrix(L_A, 1, N, 1, N);
    free_matrix(U_A, 1, N, 1, N);
    fclose(file_ptr);
    free_matrix(A_jednostkowa, 1, N, 1, N);
}
void inicjalizuj_macierz(float ***A)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            (*A)[i][j] = (float)(1.0) / (i + j);
        }
    }
}

void inicjalizuj_L(float ***L, float **A)
{
    *L = matrix(1, N, 1, N);
    inicjalizuj_0(L);
    for (int i = 1; i <= N; i++)
        (*L)[i][i] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (j == i)
                continue;
            else if (j > i)
                break;
            else
            {
                (*L)[i][j] = A[i][j];
            }
        }
    }
}
void inicjalizuj_U(float ***U, float **A)
{
    (*U) = matrix(1, N, 1, N);
    inicjalizuj_0(U);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (j == i)
            {
                (*U)[i][j] = A[i][j];
            }

            else if (j > i)
            {
                (*U)[i][j] = A[i][j];
            }
        }
    }
}
void inicjalizuj_0(float ***A)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            (*A)[i][j] = 0;
    }
}
float wyznacznik(float **A)
{
    float iloczyn = 1.0;
    for (int i = 1; i <= N; i++)
    {
        iloczyn *= A[i][i];
    }
}
void rozwiaz_wektor(float **A, int *invector, float **free_memb, int iteracja)
{
    (*free_memb)[iteracja] = 1;
    lubksb(A, N, invector, *free_memb);
}
void zeruj_vect(float **vec)
{
    for (int i = 1; i <= N; i++)
        (*vec)[i] = 0;
}
void d_inicjalizuj_wektor(int **A)
{
    *A = ivector(1, N);
    for (int i = 1; i <= N; i++)
        (*A)[i] = 0;
}
void pomnoz(float **A, float **B, float ***C)
{
    float suma;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            suma = 0;
            for (int k = 1; k <= N; k++)
            {
                suma += A[i][k] * B[k][j];
            }
            (*C)[i][j] = suma;
        }
    }
}
float max_value(float **A)
{
    float max = abs(A[1][1]);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (abs(A[i][j]) > max)
            {
                max = A[i][j];
            }
        }
    }
    return max;
}
