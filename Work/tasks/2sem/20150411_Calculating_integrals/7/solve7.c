#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

double function(double x)
{
    return x * x;
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
	double h = (b - a) / (2 * n);
	double x = a, x_middle, x_next, f_x = f(x), f_x_middle, f_x_next, 
	       difference12, difference23, difference123,
	       sum = 0;
	int idx;
	for (idx = 0; idx < n; idx++)
	{
		x_middle = x + h;
		x_next = x + 2 * h;
		f_x_middle = f(x_middle);
		f_x_next = f(x_next);
		difference12 = (f_x_middle - f_x) / h;
		difference23 = (f_x_next - f_x_middle) / h;
		difference123 = (difference23 - difference12) / (2 * h);
		sum += 2 * (f_x - x * difference12 + x * x_middle * difference123) * 
		       (sqrt(fabs(x_next)) * sign(x_next) - sqrt(fabs(x)) * sign(x));
		sum += 2.0 / 3 * (difference12 - (x + x_middle) * difference123) *
		      (x_next * sqrt(fabs(x_next)) * sign(x_next) - x * sqrt(fabs(x)) * sign(x));
		sum += 2.0 / 5 * difference123 *
		      (x_next * x_next * sqrt(fabs(x_next)) * sign(x_next) - x * x * sqrt(fabs(x)) * sign(x));
		x = x_next;
		f_x = f_x_next;
	}
	printf("Answer: %.10f\n\n", sum);
	return;
}
