#include "Main.h"
#include "/home/hubert/Numerical_recipes/nrutil.h"
#include "/home/hubert/Numerical_recipes/nrutil.cpp"
#include "/home/hubert/Numerical_recipes/gaussj.cpp"

int main()
{
    float h, xmin = 5, xmax = -5;

    int n = 5;

    double xx[n + 6];

    double *xw = &xx[2];
    double yw[n];
    h = (xmax - xmin) / (n - 1);

    for (int i = -2; i <= (n + 3); i++)
        xw[i] = xmin + h * (i - 1);
    for (int i = 1; i <= n; i++)
        yw[i] = f1_get_value(xw[i]);

    float **A = matrix(1, n, 1, n);
    float *result = vector(1, n);
    float *vec = vector(1, n);
    float **B = matrix(1, n, 1, 1);
    double alpha, beta;

    alpha = f1_derivate(-5);
    beta = f1_derivate(5);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            A[i][j] = 0;
        A[i][i] = 4;
    }

    for (int i = 1; i < n; i++)
        A[i][i + 1] = 1;

    A[1][2] = 2;

    for (int i = 2; i < n; i++)
        A[i][i - 1] = 1;

    A[n][n - 1] = 2;

    vec[1] = yw[0] + ((fabs((fabs(xw[-1]) - fabs(xw[1])))) / 3.0) * alpha;

    for (int i = 2; i < n; i++)
        vec[i] = yw[i];

    vec[n] = yw[n] - ((fabs((fabs(xw[n - 1]) - fabs(xw[n + 1])))) / 3.0) * beta;

    for (int i = 1; i <= n; i++)
        B[i][1] = vec[i];

    gaussj(A, n, B, 1);

    for (int i = 1; i <= n; i++)
        std::cout << B[i][1] << std::endl;

    // double cnew[n + 1];

    // cnew[0] = B[3][1] - ((fabs((fabs(xw[-1]) - fabs(xw[1])))) / 3.0) * alpha;
    // cnew[n + 1] = B[n][1] + ((fabs((fabs(xw[n - 1]) - fabs(xw[n + 1])))) / 3.0) * beta;




    free_matrix(A, 1, n, 1, n);
    free_vector(result, 1, n);
    free_vector(vec, 1, n);
    free_matrix(B, 1, n, 1, 1);

    return 0;
}