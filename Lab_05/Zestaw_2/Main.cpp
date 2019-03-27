#include "Functions.cpp"

int main(void)
{
    //// init ////

    gsl_matrix *A_matrix = gsl_matrix_calloc(N, N);
    gsl_matrix *W_matrix = gsl_matrix_calloc(N, N);
    gsl_matrix *temp_matrix = gsl_matrix_calloc(N, N);
    gsl_matrix *X_matrix = gsl_matrix_calloc(N, N);
    gsl_matrix *D_matrix = gsl_matrix_calloc(N, N);
    gsl_matrix *temp_multiply_matrix = gsl_matrix_calloc(N,N);

    gsl_vector *start_vector = gsl_vector_calloc(N);
    gsl_vector *x_vector = gsl_vector_calloc(N);

    FILE *fp;

    //// main ////

    intialiaze_matrix(&A_matrix); // initialization of main matrix

    copy_matrix(&W_matrix, A_matrix); // initialization of iterator matrix

    fp = fopen("dane.dat", "w");
    if (!fp)
    {
        printf("ERR while opening file! Leaving...\n");
        abort();
    }

    int K_val = N;
    float lambda;

    for (int k = 0; k < K_val; k++)
    {
        fprintf(fp, "k= %d\n", k);
        iniialiaze_start_vector(&start_vector);
        for (int i = 1; i <= IT_MAX; i++)
        {
            multiply_matrix_vector(W_matrix, start_vector, &x_vector);
            lambda = multiply_vector_vector(x_vector, start_vector) / multiply_vector_vector(start_vector, start_vector);
            copy_normed_vector(&start_vector, x_vector);
            fprintf(fp, "%f ", lambda);
        }
        fprintf(fp, "\n");
        
        for (int z = 0; z < N; z++)
        {
            gsl_matrix_set(X_matrix, k, z, gsl_vector_get(x_vector, z));
        }

        multiply_vector_vector_to_matrix(start_vector, start_vector, &temp_matrix);
        multiply_matrix_const(lambda, &temp_matrix);
        substract_matrices(W_matrix, temp_matrix, &W_matrix);
    }



    transpose_matrix(&X_matrix);
    matrix_multiplier(X_matrix,A_matrix,&temp_multiply_matrix);
    transpose_matrix(&X_matrix);
    matrix_multiplier(temp_multiply_matrix,X_matrix,&D_matrix);

    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            fprintf(fp,"%f ",gsl_matrix_get(D_matrix,i,j));
        }
        fprintf(fp,"\n");
    }

    //// free memory ////

    gsl_matrix_free(A_matrix);
    gsl_matrix_free(W_matrix);
    gsl_matrix_free(temp_matrix);
    gsl_matrix_free(X_matrix);
    gsl_matrix_free(D_matrix);
    gsl_matrix_free(temp_multiply_matrix);

    gsl_vector_free(x_vector);
    gsl_vector_free(start_vector);

    fclose(fp);
}