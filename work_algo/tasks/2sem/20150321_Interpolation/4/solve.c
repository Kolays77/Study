#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"
#include "read.h"

#define EPS 0.000001

int make_f(double *x, double *func, double *dif, int n)
{
	int i, counter;
	for (i = n - 1; i >= 1; i--)
	{
		if (fabs(x[i] - x[i - 1]) < EPS)
		{
			printf("Error data: x[%d] = x[%d]\n", i - 1, i);
			return 0;
		}
		func[i] = (func[i] - func[i - 1]) / (x[i] - x[i - 1]);
	}
	//print_function(x, func, dif, n);
	for (counter = 2; counter <= 2 * n - 1; counter++)
	{
		for (i = n - 1; i >= counter / 2; i--)
		{
			if (fabs(x[i] - x[i - counter / 2]) < EPS)
			{
				printf("Error data: x[%d] = x[%d]\n", i - counter / 2, i);
				return 0;
			}
			dif[i] = (dif[i] - func[i]) / (x[i] - x[i - counter / 2]);
			if (i - (counter + 1) / 2 < 0)
			{
				continue;
			}
			if (fabs(x[i] - x[i - (counter + 1) / 2]) < EPS)
			{
				printf("Error data: x[%d] = x[%d]\n", i - counter / 2, i);
				return 0;
			}
			func[i]  = (func[i] - dif[i - 1]) / (x[i] - x[i - (counter + 1) / 2]);
					
		}
		//print_function(x, func, dif, n);
	}
	return 1;
}

double calculate_answer(double *x, double *func, double *dif, int n, double x0)
{
	int idx;
	double answer = 0;
	for (idx = n - 1; idx >= 1; idx--)
	{
		answer += dif[idx];
		answer *= (x0 - x[idx]);
		answer += func[idx];
		answer *= (x0 - x[idx - 1]);
	}
	answer += dif[0];
	answer *= (x0 - x[0]);
	answer += func[0];
	return answer;
}
