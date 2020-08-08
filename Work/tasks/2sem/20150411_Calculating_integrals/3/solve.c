#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

double function(double x)
{
	return exp(1 / x);
}

double differential2(double x)
{
	return exp(1 / x) * (2 * x + 1) / (x * x * x * x);
}

void calculate_differential2(double (*f)(double),
							  double x,
							  double h)
{
	double dif = (f(x + h) - 2 * f(x) + f(x - h)) / (h * h),
	       real_dif = differential2(x);
	printf("f''(x) = %4.10f        Abcolutely error: %e\n\n", dif, fabs(dif - real_dif));
}
