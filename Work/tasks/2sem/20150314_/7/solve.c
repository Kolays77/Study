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

void mult_by_const(double* x, double c, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        x[i] *= c;
    }
}

void add_constbycol(double* x, double* y, double c, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        x[i] += y[i] * c;
    }
}

void find_x_Uxisb(double* A, double* b, double* x, int n)
{
    int i = n-1, j;
    double s;
    double* Ai = A + i * n;
    for (i = n - 1; i >= 0; i--, Ai -= n)
    {
        s = 0;
        for (j = i + 1; j < n; j++)
        {
            s += Ai[j] * x[j];
        }
        x[i] = (b[i] - s) / Ai[i];
    }
}

void solve7(double* A, double* x0, double* b, double* x, double* y, int n, int m, double tau)
{
    //    U(x_k - x_k-1) = tau * (b - Ax_k-1)
    int k;
    double* x_k;
    double* x_kmin1;
    double* temp;
    x_kmin1 = x0;
    x_k = x;
    for (k = 1; k <= m; k++)
    {
        //x_kmin1 = x_k-1
        matrixbycolumn_nn(A, x_kmin1, y, n);
        add_constbycol(y, b, -1, n);
        mult_by_const(y, -tau, n);
        //y = tau * (b - Ax_k-1)
        find_x_Uxisb(A, y, x_k, n);
        add_col(x_k, x_kmin1, n);
        //x_k is ready
        temp = x_k;
        x_k = x_kmin1;
        x_kmin1 = temp;
        //x_kmin1 is ready for the next operation (x_kmin1 = current x_k)
    }
    if (x_kmin1 != x)
    {
        for (k = 0; k < n; k++)
        {
            x[k] = x_kmin1[k];
        }
    }
}
