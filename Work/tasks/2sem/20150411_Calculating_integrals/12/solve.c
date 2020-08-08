#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

#define MAX_N 100000000
#define EPS 0.000001

double coord1(double t)
{
	return t - sin(t);
}

double coord2(double t)
{
	return 1 - cos(t);
}

int calculate_length(double (*x)(double),
                        double (*y)(double),
						double a,
						double b,
						double eps,
						double *result)
{
	long long n = 1, idx;
	double h, t, x_cur, y_cur, x_next, y_next, x_start = x(a), y_start = y(a);
	double s_prev = -eps - 1;
	while (n < MAX_N)
	{
		s_prev = *result;
		(*result) = 0;
		//printf("%f OOOOOOO\n", *result);
		h = (b - a) / n;
		x_cur = x_start; y_cur = y_start;
		t = a + h;
		for (idx = 1; idx <= n; idx++)
		{
			x_next = x(t); y_next = y(t += h);
			//printf("%f\n", sqrt((y_next - y_cur) * (y_next - y_cur) + (x_next - x_cur) * (x_next - x_cur)));
			(*result) += sqrt((y_next - y_cur) * (y_next - y_cur) + (x_next - x_cur) * (x_next - x_cur));
			x_cur = x_next; y_cur = y_next;
		}
		if (fabs(s_prev - (*result)) < eps)
		{
			return n;
		}
		//printf("%f XOXO\n", *result);
		x_cur = x_next;
		y_cur = y_next;
		n *= 2;
	}
	return -1;
}
