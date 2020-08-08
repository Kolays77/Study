#include <stdio.h>
#include <stdlib.h>
#include "head.h"

void product(double *matrix1, double *matrix2, double *answer, int n, int m, int k)
{
	int idx1, idx2, idx_;
	double buffer;
	double *pointer1 = matrix1,
		   *pointer2 = matrix2;
	      
	for (idx_ = 0; idx_ < n; idx_++)
	{
		for (idx1 = 0; idx1 < k; idx1++)
		{
			buffer = 0;
			for (idx2 = 0; idx2 < m; idx2++)	
			{
				buffer += (pointer1[idx2] * pointer2[idx2 * k]);
			}
			answer[idx_ * k + idx1] = buffer;
			pointer2++;
		}
		pointer1 += m;
		pointer2 = matrix2;
	}
	return;
}
