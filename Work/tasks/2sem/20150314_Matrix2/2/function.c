#include <stdio.h>
#include <stdlib.h>
#include "head.h"

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

void sum_V(double *vector1,
           double *vector2,
           double *vector3,
           int n)
{
	int idx;
	for (idx = 0; idx < n; idx++)
	{
		vector3[idx] = vector2[idx] + vector1[idx];
	}
	return;
}

void dif_V(double *vector1,
           double *vector2,
           double *vector3,
           int n)
{
	int idx;
	for (idx = 0; idx < n; idx++)
	{
		vector3[idx] = vector1[idx] - vector2[idx];
	}
	return;
}

void product_VN(double *vector1,
                int n,
                double tau)
{
	int idx;
	for (idx = 0; idx < n; idx++)
	{
		vector1[idx] *= tau;
	}
	return;
}

int solve(double *matrix,
             double *vector,
             double *vector2,
             int n,
             int m,
             double tau,
             double *vector_answer)
{
	double *tmp;
	int idx;
	for (idx = 0; idx < m; idx++)
	{	
		product_MV(matrix, vector, vector_answer, n);
		dif_V(vector2, vector_answer, vector_answer, n);
		product_VN(vector_answer, n, tau);
		sum_V(vector_answer, vector, vector_answer, n);
		
		tmp = vector_answer;
		vector_answer = vector;
		vector = tmp;
	}
	return idx % 2;
}
