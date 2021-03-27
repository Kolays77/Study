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

void add_col(double* x, double* y, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        x[i] += y[i];
    }
}

void solve2(double* A, double* x0, double* b, double* x, int n, int m, double tau)
{
    //x_k = b * tau + (E - tau * A) * x_k-1
    int i, j, k;
    double* x_k;
    double* x_kmin1;
    double* temp;
    for (i = 0; i < n; i++)
    {
        b[i] *= tau;
    }
    //b -> b * tau;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            A[i * n + j] *= -tau;
        }
        A[i * n + i] += 1;
    }
    //A -> (E - tau * A)
    x_kmin1 = x0;
    x_k = x;
    for (k = 1; k <= m; k++)
    {
        matrixbycolumn_nn(A, x_kmin1, x_k, n);
        add_col(x_k, b, n);
        temp = x_k;
        x_k = x_kmin1;
        x_kmin1 = temp;
    }
    if (x_kmin1 != x)
    {
        for (k = 0; k < n; k++)
        {
            x[k] = x_kmin1[k];
        }
    }
}