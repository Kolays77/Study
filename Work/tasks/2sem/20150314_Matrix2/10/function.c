#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"
#include "read_vector.h"

#define MAX_N 25000
#define MAX 150
#define EPS 0.0000001

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

int solve(double *matrix,
             double *vector,
             double *vector2,
             int n,
             int m,
             double *vector_answer)
{
	double *tmp, dot_prod, tau, buffer[MAX_N], buffer2[MAX_N];
	int idx;
	
	for (idx = 0; idx < m; idx++)
	{	
		product_MV(matrix, vector, vector_answer, n);
		dif_V(vector2, vector_answer, vector_answer, n);
		product_TMV(matrix, vector_answer, buffer, n);
		
		
		product_MV(matrix, buffer, vector_answer, n);
		product_TMV(matrix, vector_answer, buffer2, n);
		
		tau = -dot_product(buffer2, buffer, n);
		dot_prod = dot_product_sqr(buffer2, n);
		
		if (fabs(dot_prod) < EPS)
		{
			printf("Cannot divide by 0!\n");
			return 0;
		}
		
		tau /= dot_prod;
		product_VN(buffer, n, tau);
		sum_V(vector, buffer, vector_answer, n);
		
		tmp = vector_answer;
		vector_answer = vector;
		vector = tmp;
	}
	if (idx % 2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}