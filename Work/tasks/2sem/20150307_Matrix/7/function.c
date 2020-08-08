#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int swap_coloumns(double *matrix, int n, int m, int first, int second)
{
	int idx, dif = 0;
	double buffer;
	double *pointer1 = matrix + first,
	       *pointer2 = matrix + second;
	if (first >= m || second >= m)
	{
		return 0;
	}
	for (idx = 0; idx < n; idx++)
	{
		buffer = pointer1[dif];
		pointer1[dif] = pointer2[dif];
		pointer2[dif] = buffer;
		dif += m;
	}
	return 1;
}
