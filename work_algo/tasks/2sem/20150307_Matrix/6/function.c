#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int swap_strings(double *matrix, int n, int m, int first, int second)
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
		buffer = pointer1[idx];
		pointer1[idx] = pointer2[idx];
		pointer2[idx] = buffer;
	}
	return 1;
}
