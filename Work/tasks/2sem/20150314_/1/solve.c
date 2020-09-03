#include "solve.h"
#include <stdio.h>

double dot_prod(double* x, double* y, int n)
{
    int i;
    double res = 0;
    for (i = 0; i < n; i++)
    {
        res += x[i] * y[i];
    }
    return res;
}

void matrixbycolumn_nn(double* A, double* x, double* x_ans, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        x_ans[i] = dot_prod(A + i * n, x, n);
    }
}

double solve1(double* A, double* x0, double* x1, int n, int m)
{
    int k;
    double *x_k, *x_kmin1;
    double *temp;
    x_kmin1 = x0;
    x_k = x1;
    for (k = 1; k <= m + 1; k++)
    {
        matrixbycolumn_nn(A, x_kmin1, x_k, n);
        temp = x_k;
        x_k = x_kmin1;
        x_kmin1 = temp;
    }
    //x_m is in x_kmin1, x_m+1 is in x_k
    return dot_prod(x_kmin1, x_k, n) / dot_prod(x_k, x_k, n);
}











