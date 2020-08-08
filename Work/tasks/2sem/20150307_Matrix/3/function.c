#include <stdio.h>
#include <stdlib.h>
#include "head.h"

void transposition(double *matrix, int n)
{
	int idx1, idx2;
	double buffer;
	double *pointer1, *pointer2;
	for (idx1 = 1; idx1 < n; idx1++)
	{
		pointer1 = matrix + idx1 * n;
		pointer2 = matrix + idx1;
		for (idx2 = 0; idx2 < idx1; idx2++)
		{
			int idx_ = idx2 * n;
			buffer = pointer1[idx2];
			pointer1[idx2] = pointer2[idx_];
			pointer2[idx_] = buffer;
		}
	}
	return;
}
