#include <stdio.h>
#include <stdlib.h>
#include "head.h"

#define MAX_N 25000
#define EPS 0.0000001

int check_M(double *matrix,
             int n)
{
	int idx;
	for (idx = 0; idx < n * n; idx += (n + 1))
	{
		if (matrix[idx] < EPS && matrix[idx] > -EPS)
		{
			return 0;
		}  
	}
	return 1;
}

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

void make_D(double *matrix,
            double *diagonal,
            int n)
{
	int idx;
	double *pointer = matrix;
	for (idx = 0; idx < n; idx++)
	{
		diagonal[idx] = 1 / pointer[0];
		pointer += (n + 1);
	}
	return;
}

void product_DV(double *diagonal,
               double *vector,
               int n)
{
	int idx;
	for (idx = 0; idx < n; idx++)
	{
		vector[idx] *= diagonal[idx];
	}
	return;
}

void product_DM(double *diagonal,
                double *matrix,
                double *product,
                int n)
{
	int idx1, idx2;
	double *pointer2 = product, *pointer1 = matrix, buffer;
	for (idx1 = 0; idx1 < n; idx1++)
	{
		buffer = diagonal[idx1];
		for (idx2 = 0; idx2 < n; idx2++)
		{
			pointer2[idx2] = buffer * pointer1[idx2];
		}
		pointer2 += n;
		pointer1 += n;
	}
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

double dot_product_sqr(double *vector,
                   int n)
{
	int idx;
	double result;
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
	double result;
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
             double tau,
             double *vector_answer)
{
	double *tmp, dot_prod, buffer[MAX_N];
	int idx;
	for (idx = 0; idx < m; idx++)
	{	
		product_MV(matrix, vector, vector_answer, n);
		dif_V(vector2, vector_answer, vector_answer, n);
		product_VN(vector_answer, n, tau);
		make_D(matrix, buffer, n);
		product_DV(buffer, vector_answer, n);
		sum_V(vector_answer, vector, vector_answer, n);
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