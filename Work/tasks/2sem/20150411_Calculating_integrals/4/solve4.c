#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

double function(double x)
{
    return x;
}

void calculate_integral(double (*f)(double),
						double a,
						double b,
						int n)
{
	double h = (b - a) / n;
	double x = a, sum = 0;
	int idx;
	sum = (f(a) + f(b)) / 2;
	for (idx = 1; idx < n; idx++)
	{
		sum += f(idx * h + x);
	}
	sum *= h;
	printf("Answer: %.10f\n\n", sum);
	return;
}
