#include "Main.h"

int main(void)
{
    FILE *file_ptr;
    gsl_matrix *A;
    gsl_matrix *B;
    gsl_vector *eval;
    gsl_matrix *evec;
    A = gsl_matrix_calloc(n, n);
    B = gsl_matrix_calloc(n, n);
    evec = gsl_matrix_calloc(n, n);
    eval = gsl_vector_calloc(n);
    gsl_eigen_gensymmv_workspace *w = gsl_eigen_gensymmv_alloc(n);
    init_matrix(A);
    init_matrix(B);

    file_ptr = fopen("dane.dat", "w");
    if (!file_ptr)
    {
        printf("ERR while opening file! Leaving...\n");
        return -1;
    }
    fprintf(file_ptr, "%5s    %-10s    %-10s    %-10s    %-10s    %-10s    %-10s\n", "alfa", "wartosc1", "wartosc2", "wartosc3", "wartosc4", "wartosc5", "wartosc6");
    for (int alfa = 0; alfa <= 100; alfa += 2)
    {
        init_A(&A);
        init_B(&B, alfa);
        gsl_eigen_gensymmv(A, B, eval, evec, w);
        gsl_eigen_gensymmv_sort(eval, evec, GSL_EIGEN_SORT_ABS_ASC);
        fprintf(file_ptr, "%5d    %10g    %10g    %10g    %10g    %10g    %10g\n", alfa, gsl_vector_get(eval, 0), gsl_vector_get(eval, 1), gsl_vector_get(eval, 2),
                gsl_vector_get(eval, 3), gsl_vector_get(eval, 4), gsl_vector_get(eval, 5));
    }
    gsl_matrix_free(evec);
    gsl_matrix_free(A);
    gsl_matrix_free(B);
    gsl_vector_free(eval);
    gsl_eigen_gensymmv_free(w);
    fclose(file_ptr);
}
void init_matrix(gsl_matrix *A)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            (i == j) ? gsl_matrix_set(A, i, j, 1) : gsl_matrix_set(A, i, j, 0);
        }
    }
}

void init_A(gsl_matrix **A)
{
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n - 1; j++)
        {
            gsl_matrix_set(*A, i, j, (-cronecker(i, j + 1) + 2 * cronecker(i, j) - cronecker(i, j - 1)) / ((float)L / (float)(n + 1)));
        }
}

void init_B(gsl_matrix **A, int alfa)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            gsl_matrix_set(*A, i, j, (p_function(alfa, i) / N) * cronecker(i, j));
        }
}
int cronecker(int i, int j)
{
    return (i == j) ? 1 : 0;
}
float p_function(int alfa, int i)
{
    float x = -(L/2) + ((L/(n+1))*(i+1));
    return (1 + 4 * (alfa * pow(x, 2)));
}