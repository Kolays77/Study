#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

#define MAX_ITERATION 100000
#define EPS 0.0000000000000001

double function(double x)
{
	return 1 / x - x;	
}


int make_d(double *x, double *y, double *f, int n)
{
	int i, counter;
	for (i = 0; i < n; i++)
	{
		f[i] = y[i];
	}
	for (counter = 1; counter < n; counter++)
	{
		for (i = n - 1; i >= counter; i--)
		{
			if (fabs(x[i] - x[i - counter]) < EPS)
			{
				printf("Error data: x[%d] = x[%d]\n", i - counter, i);
				return -1;
			}
			f[i] = (f[i] * (-x[i - counter]) + f[i - 1] * (x[i])) / (x[i] - x[i - counter]);
		}
	}
	return 0;
}

int find_root(double *d,
			  int m,
              double (*f)(double),
              double eps,
              double *answer)
{
	int count_iter;
	int max_idx, idx;
	double y_m, y_max;
	
	(void) answer;
	for (count_iter = 0; count_iter < MAX_ITERATION; count_iter++)
	{
		int result = make_d(d + m + 1, d, d + 2 * m + 1, m);
		if (result != 0)
		{
			return -1;
		}
		d[m] = d[3 * m];
		max_idx = m;
		y_max = y_m = f(d[m]);
		for (idx = m + 1; idx <= 2 * m; idx++)
		{
			if (fabs(d[idx]) > y_max)
			{
				y_max = fabs(d[idx]);
				max_idx = idx - m - 1;
			}
		}
		if (fabs(y_m) < eps)
		{
			*answer = d[m];
			return count_iter;
		}
		if (m == max_idx)
		{
			return -1;
		}
		d[max_idx] = d[m];
		d[max_idx + m + 1] = y_m;
	 	
	}
	*answer = d[m];
	return count_iter;
}
