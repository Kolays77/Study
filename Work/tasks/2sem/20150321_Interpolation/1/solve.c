#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

#define EPS 0.000001

double solve(double *x, double *y, int n, double x0)
{
	int i, j;
	double y0 = 0, current;
	for (i = 0; i < n; i++)
	{
		current = 1;
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}
			if (fabs(x[i] - x[j]) < EPS)
			{
				printf("Error data: x[%d] = x[%d]!\n", i, j);
				break;
			}
			current *= ((x0 - x[j]) / (x[i] - x[j]));
		}
		y0 += y[i] * current;
	}
	return y0;
}
