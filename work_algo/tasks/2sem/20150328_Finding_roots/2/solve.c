#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

#define MAX_ITERATION 100000
#define EPS 0.0000000000000001

double function(double x)
{
	return exp(x) - x * x * x * x *x;
}

double differential(double x)
{
	return exp(x) - 5 * x * x * x * x;
}

int find_root(double x0,
              double (*f)(double),
              double (*d)(double),
              double eps,
              double *answer)
{
	int count_iter;
	double f_k = f(x0), d_k = d(x0), x_k = x0;
	(void) answer;
	for (count_iter = 0; count_iter < MAX_ITERATION; count_iter++)
	{
		if (fabs(d_k) < eps)
		{
			return -1;
		}
		if (fabs(f_k) < eps)
		{
			break;
		}
		x_k -= f_k / d_k;
		f_k = f(x_k);
		d_k = d(x_k);
	}
	*answer = x_k;
	return count_iter;
}
