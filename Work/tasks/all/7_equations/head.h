#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define EPS 1e-16

double function (double x);
double differential (double x);

#define MAX_NUM_ITERATIONS 1e5

int find_root1 (double (*f) (double),
                double left_board,
                double right_board,
                double eps,
                double *answer);

int find_root2 (double (*f) (double),
                double (*dif) (double),
                double x_start,
                double eps,
                double *answer);

int find_root3 (double (*f) (double),
                double left_board,
                double right_board,
                double eps,
                double *answer);

int find_root4 (double (*f) (double),
                double left_board,
                double right_board,
                double eps,
                double *answer);

int find_root5 (double (*f) (double),
                double x0,
                double x2,
                double x1,
                double eps,
                double *answer);

int find_root6 (double (*f)(double),
                double *dif,
                double left_board,
                double right_board,
                int deg,
                double eps,
                double *answer);
int make_dif (double *x, double *y, double *f, int n);

int find_root7 (double (*f) (double),
                double (*dif) (double),
                double x_start,
                double eps,
                double *x);

#define NUMBER_OF_STEPS 10
int find_max8 (double (*f) (double),
               double left_board,
               double right_board,
               double eps,
               double *answer);

int find_max9 (double (*f) (double),
               double left_board,
               double right_board,
               double eps,
               double *answer);

int find_max10 (double (*f) (double),
                double x0,
                double x2,
                double x1,
                double eps,
                double *answer);
