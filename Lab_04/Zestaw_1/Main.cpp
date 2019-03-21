#include "Main.h"

int main(void)
{
    //// initialization ////

    // matrices //

    float **A;
    float **Y;
    float **X;

    // vectors //

    float *d;
    float *e;

    // File //

    FILE *file_ptr;

    // Other //

    std::vector<float> beta;

    // alloc memory //

    A = matrix(1, n, 1, n);
    Y = matrix(1, n, 1, n);
    X = matrix(1, n, 1, n);
    d = vector(1, n);
    e = vector(1, n);

    file_ptr = fopen("dane.dat", "w");
    if (!file_ptr)
    {
        printf("ERR while opening file! Leaving...\n");
        return -1;
    }

    // main //

    intialiaze_matrix_I_0(&Y);
    intialiaze_matrix(&A);
    tred2(A, n, d, e);

    fprintf(file_ptr, "Macierz przekształcenia P:\n\n");

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            fprintf(file_ptr, "   %3g    ", A[i][j]); // wpisywanie do pliku macierzy przeksztalcenia P
        }
        fprintf(file_ptr, "\n");
    }

    tqli(d, e, n, Y);

    multiply_matrices(A, Y, &X);

    fprintf(file_ptr, "Wektory własne macierzy A:\n\n");

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            fprintf(file_ptr, "   %3g    ", X[i][j]); // wpisywanie do pliku macierzy przeksztalcenia P
        }
        fprintf(file_ptr, "\n");
    }

    intialiaze_matrix(&A);

    for (int i = 1; i <= n; i++)
    {
        beta.emplace_back(get_beta(A, X, i));
    }

    fprintf(file_ptr, "Wartosci wlasne: \n");

    for (int i = 1; i <= n; i++)
        fprintf(file_ptr, " %3f ", d[i]);

    fprintf(file_ptr, "\n wartosci beta: \n");

    for (int i = 0; i < n; i++)
        fprintf(file_ptr, " %3f ", beta[i]);

    // free memory //

    free_matrix(A, 1, n, 1, n);
    free_matrix(Y, 1, n, 1, n);
    free_matrix(X, 1, n, 1, n);

    free_vector(d, 1, n);
    free_vector(e, 1, n);
    fclose(file_ptr);
}

void intialiaze_matrix(float ***matrix)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            (*matrix)[i][j] = sqrt(i + j);
        }
    }
}
void intialiaze_matrix_I_0(float ***I_0_matrix)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                (*I_0_matrix)[i][j] = 1;
            else
                (*I_0_matrix)[i][j] = 0;
        }
    }
}

float get_beta(float **matrix_A, float **matrix_Y, int column)
{
    float *temp_vec = vector(1, n);
    float *Y_vector = vector(1, n);
    float temp_sum;
    for (int i = 1; i <= n; i++)
    {
        Y_vector[i] = matrix_Y[i][column];
    }

    for (int i = 1; i <= n; i++)
    {
        temp_sum = 0;
        for (int j = 1; j <= n; j++)
        {
            temp_sum += matrix_A[i][j] * Y_vector[j];
        }
        temp_vec[i] = temp_sum;
    }
    temp_sum = (multiply_vector_vector(Y_vector, temp_vec) / multiply_vector_vector(Y_vector, Y_vector));

    free_vector(Y_vector, 1, n);
    free_vector(temp_vec, 1, n);
    return temp_sum;
}

float multiply_vector_vector(float *vect1, float *vect2)
{
    float sum = 0;
    for (int i = 1; i <= n; i++)
        sum += vect1[i] * vect2[i];
    return sum;
}
void multiply_matrices(float **A, float **B, float ***C)
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
