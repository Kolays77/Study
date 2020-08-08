#include <stdio.h>
#include <stdlib.h>
#include "head.h"

double trace(double *matrix, int n)
{
	int idx, difference = n + 1;
	double *pointer = matrix;
	double sum = 0;
	for (idx = 0; idx < n; idx++)
	{
		sum += pointer[0];
		pointer += difference;
	}
	return sum;
}
