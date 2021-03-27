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

double dotprod_Ax_Ax(double* A, double* x, int n)
{
    int i, j;
    double res = 0, t;
    for (i = 0; i < n; i++)
    {
        t = dot_prod(A + i * n, x, n);
        res += t * t;
    }
    return res;
}

void solve3(double* A, double* x0, double* b, double* x, double* r, int n, int m)
{
    //    x_k = x_k-1 - tau_k-1 * A * x_k-1 + b * tau_k-1
    int k;
    double* x_k;
    double* x_kmin1;
    double* temp;
    double tau;
    x_kmin1 = x0;
    x_k = x;
    matrixbycolumn_nn(A, x0, r, n);
    add_constbycol(r, b, -1, n);
    tau = dot_prod(r, r, n) / dotprod_Ax_Ax(A, r, n);
    for (k = 1; k <= m; k++)
    {
        //x_kmin1 = x_k-1, tau = tau_k-1, r = r_k-1
        matrixbycolumn_nn(A, x_kmin1, x_k, n);
        mult_by_const(x_k, -tau, n);
        add_col(x_k, x_kmin1, n);
        add_constbycol(x_k, b, tau, n);
        //x_k is ready
        //    r_k = Ax_k - b
        matrixbycolumn_nn(A, x_k, r, n);
        add_constbycol(r, b, -1, n);
        //r = r_k now
        //    tau_k = (r_k, r_k) / (Ar_k, Ar_k)
        tau = dot_prod(r, r, n) / dotprod_Ax_Ax(A, r, n);
        //tau = tau_k now
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
