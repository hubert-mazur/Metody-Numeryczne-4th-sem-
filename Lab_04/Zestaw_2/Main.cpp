#include "Main.h"

int main(void)
{
    //// initialization ////

    // matrices //

    float **H;
    float **Y;
    float **X;

    // vectors //

    float *d;
    float *e;

    int *index;

    FILE *file_ptr;

    //// alloc memory ////

    H = matrix(1, n, 1, n);
    Y = matrix(1, n, 1, n);
    X = matrix(1, n, 1, n);

    d = vector(1, n);
    e = vector(1, n);

    index = ivector(1, n);

    file_ptr = fopen("dane.dat", "w");

    if (file(file_ptr))
        ;
    else
        return -1;

    //// main ////

    intialiaze_main_matrix(&H);

    intialiaze_Y_matrix(&Y);

    intialiaze_matrix_null(&X);

    intialiaze_vector_null(&d);
    intialiaze_vector_null(&e);

    tred2(H, n, d, e);
    tqli(d, e, n, Y);
    pomnoz(H, Y, &X);
    sort(&d, &index);
    file_print(X, index, file_ptr);

    //// delete memory ////

    free_matrix(H, 1, n, 1, n);
    free_matrix(Y, 1, n, 1, n);
    free_matrix(X, 1, n, 1, n);
    free_vector(d, 1, n);
    free_vector(e, 1, n);
    free_ivector(index, 1, n);
    fclose(file_ptr);
}

void intialiaze_matrix_null(float ***matrix)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            (*matrix)[i][j] = 0;
}

void intialiaze_vector_null(float **vector)
{
    for (int i = 1; i <= n; i++)
        (*vector)[i] = 0;
}

void intialiaze_main_matrix(float ***matrix)
{
    int l = 0;
    for (int i = 1; i <= nx; i++)
    {
        for (int j = 1; j <= ny; j++)
        {
            l = j + (i - 1) * ny;
            for (int k = 1; k <= n; k++)
                (*matrix)[l][k] = 0.;
            if (i > 1)
                (*matrix)[l][l - ny] = t; //dla i=1 nie ma sasiada z lewej strony
            if (i < nx)
                (*matrix)[l][l + ny] = t; //dla i=nx nie ma sasiada z prawej strony
            (*matrix)[l][l] = -4 * t;
            if (j > 1)
                (*matrix)[l][l - 1] = t; //dla j=1 nie ma sasiada ponizej siatki
            if (j < ny)
                (*matrix)[l][l + 1] = t; //dla j=ny nie ma sasiada powyzej siatki
        }
    }
}

void pomnoz(float **A, float **B, float ***C)
{
    float suma;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            suma = 0;
            for (int k = 1; k <= n; k++)
            {
                suma += A[i][k] * B[k][j];
            }
            (*C)[i][j] = suma;
        }
    }
}

void sort(float **d, int **index)
{
    float e1, e2, l1, l2;
    for (int l = 1; l <= n; l++)
        (*index)[l] = l; // inicjalizacja
    for (int l = 1; l <= n - 1; l++)
    {
        for (int k = n; k >= l + 1; k--)
        {
            e1 = (*d)[k - 1];
            e2 = (*d)[k];
            l1 = (*index)[k - 1];
            l2 = (*index)[k];
            if (e2 < e1)
            { //wymieniamy energie i indeksy wektorów miejscami
                (*d)[k] = e1;
                (*d)[k - 1] = e2;
                (*index)[k] = l1;
                (*index)[k - 1] = l2;
            }
        }
    }
}

bool file(FILE *file_ptr)
{
    if (file_ptr)
        return 1;
    else
        return 0;
}

void file_print(float **X, int *index, FILE *fp)
{
    int l;
    for (int i = 1; i <= nx; i++)
    {
        for (int j = 1; j <= ny; j++)
        {
            l = j + (i - 1) * ny;
            fprintf(fp, "%6d %6d ", i, j);
            for (int k = 1; k <= m; k++)
                fprintf(fp, " %12.6f ", X[l][index[k]]);
            fprintf(fp, "\n");
        }
        fprintf(fp, "\n");
    }
}
void intialiaze_Y_matrix(float ***matrix)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                (*matrix)[i][j] = 1;
            else
                (*matrix)[i][j] = 0;
}