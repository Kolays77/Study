#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

#define EPS 0.000001

int make_f(double *x, double *func, int n)
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
			func[i] = (func[i] - func[i - 1]) / (x[i] - x[i - counter]);
		}
	}
	return 1;
}

double calculate_answer(double *x, double *func, int n, double x0)
{
	int idx;
	double answer = 0;
	for (idx = n - 1; idx >= 1; idx--)
	{
		answer += func[idx];
		answer *= (x0 - x[idx - 1]);
	}
	answer += func[0];
	return answer;
}
