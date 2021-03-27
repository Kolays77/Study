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

void transmatrixbycolumn_nn(double* A, double* x, double* x_ans, int n)
{
    int i, j;
    double res;
    for (i = 0; i < n; i++)
    {
        res = 0;
        for (j = 0; j < n; j++)
        {
            res += A[j * n + i] * x[j];
        }
        x_ans[i] = res;
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
    int i;
    double res = 0, t;
    for (i = 0; i < n; i++)
    {
        t = dot_prod(A + i * n, x, n);
        res += t * t;
    }
    return res;
}

double dotprod_Atx_Atx(double* A, double* x, int n)
{
    int i, j;
    double res = 0, t;
    for (i = 0; i < n; i++)
    {
        t = 0;
        for (j = 0; j < n; j++)
        {
            t += A[j * n + i] * x[j];
        }
        res += t * t;
    }
    return res;
}

void solve10(double* A, double* x0, double* b, double* x, double* y, double* z, double* r, int n, int m)
{
    
    int k;
    double* temp;
    double tau;
    for (k = 0; k < n; k++)
    {
        x[k] = x0[k];
    }
    //r0:
    matrixbycolumn_nn(A, x0, y, n);
    add_constbycol(y, b, -1, n);
    transmatrixbycolumn_nn(A, y, r, n);
    //tau0:
    matrixbycolumn_nn(A, r, y, n);
    transmatrixbycolumn_nn(A, y, z, n);
    tau = dot_prod(z, r, n) / dot_prod(z, z, n);
    for (k = 1; k <= m; k++)
    {
        //x = x_k-1, tau = tau_k-1, r = r_k-1
        //    x_k = x_k-1 - tau_k-1 * r_k-1
        add_constbycol(x, r, -tau, n);
        //x_k is ready
        //    r_k = At(Ax_k - b)
        matrixbycolumn_nn(A, x, y, n);
        add_constbycol(y, b, -1, n);
        transmatrixbycolumn_nn(A, y, r, n);
        //r = r_k now
        //    tau_k = (AtAr_k, r_k) / (AtAr_k, AtAr_k)
        matrixbycolumn_nn(A, r, y, n);
        transmatrixbycolumn_nn(A, y, z, n);
        tau = dot_prod(z, r, n) / dot_prod(z, z, n);
        if (tau != tau)
        {
            printf("WARNING: Devision by zero.\nThere is x_%d in x now.\n", k);
            return;
        }
        //tau = tau_k now
    }
}

