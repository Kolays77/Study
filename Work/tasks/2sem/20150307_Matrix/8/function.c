#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int first_type(double *matrix, int n, int m, int first, int second, double factor)
{
	int idx;
	double buffer;
	double *pointer1 = matrix + m * first,
	       *pointer2 = matrix + m * second;
	       
	if (first >= n || second >= n)
	{
		return 0;
	}
	for (idx = 0; idx < m; idx++)
	{
		pointer2[idx] += pointer1[idx] * factor;
	}
	return 1;
}
