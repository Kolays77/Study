#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define EPS 1e-16

double function (double x);


double calculate_integral1 (double (*f) (double),
			    double left_board,
			    double right_board,
			    int n);

double calculate_integral2 (double (*f) (double),
			    double left_board,
			    double right_board,
			    int n);

int sign (double x);
double calculate_integral3 (double (*f) (double),
			    double left_board,
			    double right_board,
			    int n);

double calculate_integral4 (double (*f) (double),
			    double left_board,
			    double right_board,
			    int n);

#define MAX_NUM_ITERATIONS 1e8

int calculate_integral5 (double (*f) (double),
			 double left_board,
			 double right_board,
			 double eps,
			 double *answer);

int calculate_integral6 (double (*f) (double),
			 double left_board,
			 double right_board,
			 double eps,
			 double *answer);

double calculate_integral7 (double (*f) (double),
			    double start,
			    double eps,
			    double *answer);

double calculate_integral8 (double (*f)(double),
			    double start,
			    double eps,
			    double *answer);

#define MAX_NUM_ITERATIONS_INF 1e6

double coordinate_x (double t);
double coordinate_y (double t);

int calculate_length9 (double (*x) (double),
		       double (*y) (double),
		       double left_board,
		       double right_board,
		       double eps,
		       double *answer);
