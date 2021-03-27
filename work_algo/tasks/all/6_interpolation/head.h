#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define EPS 1e-16

double interpolation_lagrange (double *x, double *y, int n, double x0); //task1


int make_function (double *x, double *f, int n);
double interpolation_newton (double *x, double *f, int n, double x0); //task2

int interpolation_eitken (double *x, double *f, int n, double x0);//task3


int make_function (double *x, double *f, double *dif, int n);
double interpolation_lagrange (double *x, double *func, double *dif, int n, double x0); // task4

double get_sin (double x, double eps); //task5
double taylor_sin (double x, double eps);

double get_cos (double x, double eps); //task6
double taylor_cos (double x, double eps);

double get_exp (double x, double eps); //task 7
double taylor_exp (double x, double eps);

double get_log (double x, double eps); //tak8
double taylor_log (double x, double eps);
