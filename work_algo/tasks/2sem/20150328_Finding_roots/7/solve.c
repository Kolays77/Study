#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

#define MAX_ITERATION 100000
#define EPS 0.0000000000000001

double function(double x)
{
	return sqrt(x);
}

double differential(double x)
{
	return 1 / (2 * sqrt(x));
}

int find_root(double x0,
              double (*f)(double),
              double eps,
              double *x)
{
	int count_iter;
	(void) x;
	if (fabs(differential(x0)) >= 1)
	{
		return -2;
	}
	for (count_iter = 0; count_iter < MAX_ITERATION; count_iter++)
	{
		*x = f(x0);
		//printf("%e\n", *x - x0);
		if (fabs(*x - x0) < eps)
		{
			*x = x0;
			return count_iter;
		}
		x0 = *x;
	}
	*x = f(x0); 
	return -1;
}
