#include <stdio.h>
#include <stdlib.h>
#include "head.h"

void sum_matrix(double *matrix, int n)
{
	int idx1, idx2, idx_, difference = n + 1;
	double buffer;
	double *pointer1, *pointer2;
	for (idx1 = 1; idx1 < n; idx1++)
	{
		pointer1 = matrix + idx1 * n;
		pointer2 = matrix + idx1;
		for (idx2 = 0; idx2 < idx1; idx2++)
		{
			idx_ = idx2 * n;
			buffer = pointer1[idx2];
			pointer1[idx2] += pointer2[idx_];
			pointer2[idx_] += buffer;
		}
	}
	pointer1 = matrix;
	for (idx_ = 0; idx_ < n; idx_++)
	{
		pointer1[0] *= 2;
		pointer1 += difference;
	}
	return;
}
