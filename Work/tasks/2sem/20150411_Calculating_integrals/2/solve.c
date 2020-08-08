#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

double function(double x)
{
	return exp(1 / x);
}

double differential(double x)
{
	return -exp(1 / x) / (x * x);
}

void calculate_differential(double (*f)(double),
							  double x,
							  double h)
{
	double dif = (f(x + h) - f(x - h)) / (2 * h),
	       real_dif = differential(x);
	printf("f'(x) = %4.10f        Abcolutely error: %e\n\n", dif, fabs(dif - real_dif));
}
