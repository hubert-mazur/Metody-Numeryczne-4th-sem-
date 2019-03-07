#include "defs.h"
int main()
{
    A = matrix(1, N, 1, N);
    B = matrix(1, N, 1, N);
    inicjalizuj_spec(&A);
    inicjalizuj_spec(&B);
    B[1][1] = 1.1;
    std::cout << "macierz A: \n";
    wypisz(A);
    std::cout << "macierz B: \n";
    wypisz(B);
    d_inicjalizuj_wektor(&A_invector);
    d_inicjalizuj_wektor(&B_invector);
    ludcmp(A, N, A_invector, &d);
    ludcmp(B, N, B_invector, &d);
    std::cout << "macierz A po rozkladzie: \n";
    wypisz(A);
    std::cout << "macierz B po rozkladzie: \n";
    wypisz(B);
    inicjalizuj_L(&L_A, A);
    inicjalizuj_U(&U_A, A);
    inicjalizuj_L(&L_B, B);
    inicjalizuj_U(&U_B, B);
    std::cout << "\nwypisywanie macierzy L_A:\n";
    wypisz(L_A);
    std::cout << "\nwypisywanie macierzy U_A:\n";
    wypisz(U_A);
    std::cout << "\nwypisywanie macierzy L_B:\n";
    wypisz(L_B);
    std::cout << "\nwypisywanie macierzy U_B:\n";
    wypisz(U_B);
    std::cout << "pomnozone macierze L *U A: " << std::endl;
    tempr_A = matrix(1, N, 1, N);
    pomnoz(L_A, U_A, &tempr_A);
    wypisz(tempr_A);
    free_matrix(tempr_A, 1, N, 1, N);
    std::cout << "pomnozone macierze L *U B: " << std::endl;
    tempr_B = matrix(1, N, 1, N);
    pomnoz(L_B, U_B, &tempr_B);
    wypisz(tempr_B);
    free_matrix(tempr_B, 1, N, 1, N);
    A_rev = matrix(1, N, 1, N);
    B_rev = matrix(1, N, 1, N);
    f_inicjalizuj_wektor(&free_member);
    inicjalizuj_0(&A_rev);
    inicjalizuj_0(&B_rev);
    for (int i = 1; i <= N; i++)
    {
        rozwiaz_wektor(A, A_invector, &free_member, i);
        for (int j = 1; j <= N; j++)
            A_rev[j][i] = free_member[j];
        zeruj_vect(&free_member);
    }
    zeruj_vect(&free_member);
    for (int i = 1; i <= N; i++)
    {
        rozwiaz_wektor(B, B_invector, &free_member, i);
        for (int j = 1; j <= N; j++)
            B_rev[j][i] = free_member[j];
        zeruj_vect(&free_member);
    }

    std::cout << "\nMacierz odwrotna A: \n";
    wypisz(A_rev);
    std::cout << "\nMacierz odwrotna B: \n";
    wypisz(B_rev);
    inicjalizuj_spec(&A);
    inicjalizuj_spec(&B);
    B[1][1] = 1.1;
    A_jednostkowa = matrix(1, N, 1, N);
    B_jednostkowa = matrix(1, N, 1, N);
    std::cout << "\nmacierz jednostkowa A? \n";
    pomnoz(A, A_rev, &A_jednostkowa);
    wypisz(A_jednostkowa);

    std::cout << "\nmacierz jednostkowa B? \n";
    pomnoz(B, B_rev, &B_jednostkowa);
    wypisz(B_jednostkowa);
    std::cout << "\nwskazniki uwarunkowania macierzy A i B:\n";
    std::cout << "\nA: " << max_value(A) * max_value(A_rev) << "\nB: " << max_value(B) * max_value(B_rev) << "\n";
    free_matrix(L_A, 1, N, 1, N);
    free_matrix(U_A, 1, N, 1, N);
    free_matrix(L_B, 1, N, 1, N);
    free_matrix(U_B, 1, N, 1, N);
    free_matrix(A, 1, N, 1, N);
    free_matrix(B, 1, N, 1, N);
    free_ivector(A_invector, 1, N);
    free_ivector(B_invector, 1, N);
    free_vector(free_member, 1, N);
    free_matrix(A_rev, 1, N, 1, N);
    free_matrix(B_rev, 1, N, 1, N);
    free_matrix(A_jednostkowa, 1, N, 1, N);
    free_matrix(B_jednostkowa, 1, N, 1, N);
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
void wypisz(float **arr)
{
    std::cout << std::endl;
    std::cout << std::endl;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            printf("%   3f   ", arr[i][j]);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}
void inicjalizuj_spec(float ***A)
{
    unsigned int incr = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            (*A)[i][j] = incr;
            incr++;
        }
    }
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
void f_inicjalizuj_wektor(float **A)
{
    *A = vector(1, N);
    for (int i = 1; i <= N; i++)
        (*A)[i] = 0;
}
void d_inicjalizuj_wektor(int **A)
{
    *A = ivector(1, N);
    for (int i = 1; i <= N; i++)
        (*A)[i] = 0;
}
void rozwiaz_wektor(float **A, int *invector, float **free_memb, int iteracja)
{
    (*free_memb)[iteracja] = 1;
    lubksb(A, N, invector, *free_memb);
}
void inicjalizuj_0(float ***A)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            (*A)[i][j] = 0;
    }
}
void zeruj_vect(float **vec)
{
    for (int i = 1; i <= N; i++)
        (*vec)[i] = 0;
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
