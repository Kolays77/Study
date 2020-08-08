#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

double function(double x)
{
    return x;
}

int sign(double x)
{
	return (x > 0) - (x < 0);
}

void calculate_integral(double (*f)(double),
						double a,
						double b,
						int n)
{
	double h = (b - a) / n;
	double x = a, x_next, f_x = f(x), f_x_next, difference, sum = 0;
	int idx;
	for (idx = 0; idx < n; idx++)
	{
		x_next = x + h;
		f_x_next = f(x_next);
		difference = (f_x_next - f_x) / h;
		sum += 2 * (f_x - difference * x) * 
		       (sqrt(fabs(x_next)) * sign(x_next) - sqrt(fabs(x)) * sign(x));
		sum += 2.0 / 3 * difference * (fabs(x_next) * sqrt(fabs(x_next)) - fabs(x) * sqrt(fabs(x)));
		x = x_next;
		f_x = f_x_next;
	}
	printf("Answer: %.10f\n\n", sum);
	return;
}
