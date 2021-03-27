#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

double function(double x)
{
    return x * x;
}

void calculate_integral(double (*f)(double),
						double a,
						double b,
						int n)
{
	double h = (b - a) / (2 * n);
	double x = a + h, sum = 0;
	int idx;
	sum = f(a) + f(b);
	sum += (4 * f(x += h));
	for (idx = 1; idx < n; idx++)
	{
		sum += (2 * f(x += h));
		sum += (4 * f(x += h));
	}
	sum *= (h / 3);
	printf("Answer: %.10f\n\n", sum);
	return;
}
