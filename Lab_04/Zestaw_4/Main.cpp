#include "Main.h"

int main(void)
{

    //// initialization ////

    // matrices //

    gsl_matrix *A;
    gsl_matrix_complex *evec;

    // vectors //

    gsl_vector_complex *eval;
    gsl_eigen_nonsymmv_workspace *w;

    // Other //

    FILE *fp, *fp2, *fp3;

    //// alloc memory ////

    A = gsl_matrix_calloc(n, n);
    evec = gsl_matrix_complex_calloc(n, n);

    eval = gsl_vector_complex_calloc(n);
    w = gsl_eigen_nonsymmv_alloc(n);

    fp = fopen("dane.dat", "w");
    fp2 = fopen("dane2.dat", "w");
    fp3 = fopen("dane3.dat", "w");

    //// main ////

    for (int alfa = 0; alfa <= 100; alfa += 2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                x_i = -L / 2.0 + delta_x * (i + 1);
                p_i = 1.0 + 4.0 * alfa * x_i * x_i;
                gsl_matrix_set(A, i, j, ((-cronecker(i, j + 1) + 2 * cronecker(i, j) - cronecker(i, j - 1)) * N) / (p_i * delta_x * delta_x));
            }
        }
        gsl_eigen_nonsymmv(A, eval, evec, w);
        gsl_eigen_nonsymmv_sort(eval, evec, GSL_EIGEN_SORT_ABS_ASC);

        fprintf(fp, "%3d ", alfa);
        for (k = 0; k < 6; k++)
            fprintf(fp, "%12g ", sqrt(GSL_REAL(gsl_vector_complex_get(eval, k))));
        fprintf(fp, "\n");

        if (alfa == 0)
        {
            for (i = 0; i < n; i++)
            {
                x_i = -L / 2.0 + delta_x * (i + 1);
                fprintf(fp2, "%12g ", x_i);
                for (k = 0; k < 6; k++)
                    fprintf(fp2, "%12g ", (GSL_REAL(gsl_matrix_complex_get(evec, i, k))));
                fprintf(fp2, "\n");
            }
        }

        if (alfa == 100)
        {
            for (i = 0; i < n; i++)
            {
                x_i = -L / 2.0 + delta_x * (i + 1);
                fprintf(fp3, "%12g ", x_i);
                for (k = 0; k < 6; k++)
                    fprintf(fp3, "%12g ", (GSL_REAL(gsl_matrix_complex_get(evec, i, k))));
                fprintf(fp3, "\n");
            }
        }
    }

    //// free memory ////

    gsl_matrix_free(A);
    gsl_matrix_complex_free(evec);
    gsl_vector_complex_free(eval);
    gsl_eigen_nonsymmv_free(w);

    fclose(fp);
    fclose(fp2);
    fclose(fp3);
}

void init_matrix(gsl_matrix *A, int alfa)
{
}
int cronecker(int i, int j)
{
    return (i == j) ? 1 : 0;
}
float p_function(int alfa, int i)
{
    float x = -(L / 2) + ((L / (n + 1)) * (i + 1));
    return (1 + 4 * (alfa * pow(x, 2)));
}
void print_matrix(gsl_matrix *A)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < n; i++)
        {
            printf("  %3g  ", gsl_matrix_get(A, i, j));
        }
        printf("\n");
    }
}