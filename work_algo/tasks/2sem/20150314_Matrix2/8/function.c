#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"
#include "read_vector.h"

#define EPS 0.0000001
#define MAX_N 25000

void product_MV(double *matrix,
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

void product_TMV(double *matrix,
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
			buffer += (pointer_M[idx2 * n] * vector[idx2]);
		}
		product_vector[idx1] = buffer;
		pointer_M++;
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

double dot_product_sqr(double *vector,
                   int n)
{
	int idx;
	double result = 0;
	for (idx = 0; idx < n; idx++)
	{
		result += vector[idx] * vector[idx];
	}
	return result;
}

double solve(double *matrix,
             double *vector,
             double *vector2,
             int n,
             int m)
{
	double *tmp, dot_pr2, dot_pr1, buffer[MAX_N];
	int idx;
	for (idx = 0; idx < m; idx++)
	{	
		product_MV(matrix, vector, buffer, n);
		product_TMV(matrix, buffer, vector2, n);
		if (idx == m - 1)
		{
			continue;
		}
		tmp = vector2;
		vector2 = vector;
		vector = tmp;
	}
	dot_pr2 = dot_product_sqr(vector, n);
	if (fabs(dot_pr2) < EPS)
	{
		printf("Cannot divide by 0!\n");
		return -1;
	}
	dot_pr1 = dot_product(buffer, vector, n) / dot_pr2;
	return dot_pr1;
}
