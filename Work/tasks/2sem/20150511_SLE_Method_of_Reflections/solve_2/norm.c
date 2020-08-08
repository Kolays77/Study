#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "head.h"

double norm2(double *vector, int n)
{
	int idx;
	double norm = 0;
	for (idx = 0; idx < n; idx++)
	{
		norm += vector[idx] * vector[idx];
	}
	return sqrt(norm);
}

double norm_matrix(double *matrix1, double *matrix2, int n)
{
	int idx1, idx2, idx_;
	double buffer, current_sum, result = 0;
	double *pointer1 = matrix1,
		   *pointer2 = matrix2;
	      
	for (idx_ = 0; idx_ < n; idx_++)
	{
		current_sum = 0;
		for (idx1 = 0; idx1 < n; idx1++)
		{
			buffer = 0;
			for (idx2 = 0; idx2 < n; idx2++)	
			{
				buffer += (pointer1[idx2] * pointer2[idx2 * n]);
			}
			if (idx_ == idx1)
			{
				buffer--;
			}
			current_sum += fabs(buffer);
			pointer2++;
		}
		if (current_sum > result)
		{
			result = current_sum;
		}
		pointer1 += n;
		pointer2 = matrix2;
	}
	return result;
}
