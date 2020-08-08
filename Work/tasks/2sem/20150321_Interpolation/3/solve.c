#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

#define EPS 0.000001

int solve(double *x, double *func, int n, double x0)
{
	int i, counter;
	for (counter = 1; counter < n; counter++)
	{
		for (i = n - 1; i >= counter; i--)
		{
			if (fabs(x[i] - x[i - counter]) < EPS)
			{
				printf("Error data: x[%d] = x[%d]\n", i - counter, i);
				return 0;
			}
			func[i] = (func[i] * (x0 - x[i - counter]) - func[i - 1] * (x0 - x[i])) / (x[i] - x[i - counter]);
		}
	}
	return 1;
}
