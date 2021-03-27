#include <stdio.h>
#include <stdlib.h>
#include "head.h"

void product(double *matrix, double *vector, int n, int m)
{
	int idx1, idx2;
	double buffer;
	double *pointer_M = matrix;
	       
	for (idx1 = 0; idx1 < m; idx1++)
	{
		buffer = 0;
		for (idx2 = 0; idx2 < n; idx2++)
		{
			buffer += (pointer_M[idx2] * vector[idx2]);
		}
		matrix[idx1] = buffer;
		pointer_M = matrix + m;
	}
	return;
}
