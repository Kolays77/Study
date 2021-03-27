#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int is_symmetric(double *matrix, int n)
{
	int idx1, idx2;
	double *pointer1, *pointer2;
	for (idx1 = 1; idx1 < n; idx1++)
	{
		pointer1 = matrix + idx1 * n;
		pointer2 = matrix + idx1;
		for (idx2 = 0; idx2 < idx1; idx2++)
		{
			if (pointer1[idx2] != pointer2[idx2 * n])
			{
				return idx2;
			}
		}
	}
	return n;
}
