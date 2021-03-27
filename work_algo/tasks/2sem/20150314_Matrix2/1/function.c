#include <stdio.h>
#include <stdlib.h>
#include "head.h"

void product(double *matrix,
             double *vector,
             double *product_vector,
             int n)
{
	int idx1, idx2;
	double buffer;
	double *pointer_M = matrix;
	      
	for (idx1 = 0; idx1 < n; idx1++)
	{
		buffer = 0;
		for (idx2 = 0; idx2 < n; idx2++)
		{
			buffer += (pointer_M[idx2] * vector[idx2]);
		}
		product_vector[idx1] = buffer;
		pointer_M += n;
	}
	return;
}

double dot_product(double *vector1,
                   double *vector2,
                   int n)
{
	int idx;
	double result = 0;
	for (idx = 0; idx < n; idx++)
	{
		result += vector1[idx] * vector2[idx];
	}
	return result;
}

double solve(double *matrix,
             double *vector,
             double *vector2,
             int n,
             int m)
{
	double lambda, *tmp;
	int idx;
	for (idx = 0; idx <= m; idx++)
	{	
		if (idx % 2 == 0)
		{
			product(matrix, vector, vector2, n);
		}
		else
		{
			product(matrix, vector2, vector, n);
		}
	}
	if (idx % 2 == 0)
	{
		tmp = vector;
		vector = vector2;
		vector2 = tmp;
	}
	lambda = dot_product(vector, vector, n);
	if (lambda == 0)
	{
		printf("Cannot divide by 0!\n");
		return -1;
	}
	return lambda = dot_product(vector2, vector, n) / lambda;
}
