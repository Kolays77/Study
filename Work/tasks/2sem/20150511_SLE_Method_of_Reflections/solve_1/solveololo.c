#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "read_matrix.h"
#include "head.h"

#define EPS 0.00000000000000000000000000000000001
#define MAX_PRINTABLE_NUMBER 5	

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

void product_VN(double *vector,
                int n,
                double tau,
                double *result_vector)
{
	int idx;
	for (idx = 0; idx < n; idx++)
	{
		result_vector[idx] = vector[idx] * tau;
	}
	return;
}

void dif_V(double *vector1,
           double *vector2,
           double *result_vector,
           int n)
{
	int idx;
	for (idx = 0; idx < n; idx++)
	{
		result_vector[idx] = vector1[idx] - vector2[idx];
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

void product_UV(double *vectorX,
                double *vectorY,
                double *result_vector,
                int n)
{
	product_VN(vectorX, n, 2.0 * dot_product(vectorX, vectorY, n), result_vector);
	dif_V(vectorY, result_vector, result_vector, n);
	return;
}

void product_UM(double *vectorX,
                double *matrix,
                double *buffer_vector,
                int n,
                int current_n,
                int num_columns)
{
	int idx, idx1;
	double *pointer = matrix + (n - num_columns) * n + n - current_n;
	for (idx = 0; idx < num_columns; idx++)
	{
		product_UV(vectorX, pointer, buffer_vector, current_n);
		for (idx1 = 0; idx1 < current_n; idx1++)
		{
			pointer[idx1] = buffer_vector[idx1];
		}
		pointer += n;
	}
	return;
}


int return_matrix(double *matrix, double *addition, double *x, int n)
{
	int idx, k, current_n;
	double s, column_norm, norm_x;
	double *pointer = matrix, *buffer_vector;
	
	if (!(buffer_vector = (double *) malloc(n * sizeof(double))))
	{
		return -2;
	}
	for (k = 0; k < n - 1; k++)
	{
		s = 0;
		pointer = matrix + k * n;
		for (idx = k + 1; idx < n; idx++)
		{
			s += pointer[idx] * pointer[idx];
		}
		pointer = matrix + k * n + k;
		column_norm = sqrt(pointer[0] * pointer[0] + s);
		x[0] = pointer[0] - column_norm;
		norm_x = sqrt(x[0] * x[0] + s);
		/*if (fabs(s) < EPS)
		{
			continue;
		}*/
		x[0] /= norm_x;
		current_n = n - k;
		for (idx = 1; idx < current_n; idx++)
		{
			x[idx] = pointer[idx] / norm_x;
		}
		
		product_UM(x, matrix, buffer_vector, n, current_n, current_n - 1);
		//product_UM(x, matrix, buffer_vector, n, current_n, current_n);
		product_UM(x, addition, buffer_vector, n, current_n, n);
		
		pointer = matrix + k * n;
		pointer[k] = column_norm;
		for (idx = k + 1; idx < n; idx++)
		{
			pointer[idx] = 0;
		}
	}
	transposition(matrix, n);
	transposition(addition, n);
	
	if (reverse_move(matrix, addition, n, buffer_vector) < 0)
	{
		free(buffer_vector);
		return -1;
	}
	free(buffer_vector);
	return 0;
}

int reverse_move(double *matrix, double *addition, int n, double *buffer)
{
	int idx1, idx, idx2, idx_of_max = 0, cur_start_idx = 0;
	double *pointer = 0, *pointer2 = 0, div;
	for (idx = n - 1; idx >= 0; idx--)
	{
		double maxim = 1;
		cur_start_idx = 0;
		while (cur_start_idx != n && fabs(maxim) > EPS)
		{
			maxim = 0;
		for (idx2 = cur_start_idx; idx2 <= idx; idx2++)
		{
			if (maxim < fabs(matrix[idx2 * n + idx]))
			{
				maxim = fabs(matrix[idx2 * n + idx]);
				idx_of_max = idx2;
			}
		}
		idx1 = idx_of_max;
		
		cur_start_idx = idx_of_max + 1;
		div = matrix[idx1 * n + idx1];
		if (fabs(div) < EPS)
		{
			return -1;
		}
		pointer = addition + idx1 * n;
		pointer2 = matrix + idx1 * n;
		for (idx2 = 0; idx2 < idx1; idx2++)
		{
			product_VN(pointer, n, matrix[idx2 * n + idx1] / div, buffer);
			dif_V(addition + idx2 * n, buffer, addition + idx2 * n, n);
			product_VN(pointer2, n, matrix[idx2 * n + idx1] / div, buffer);
			dif_V(matrix + idx2 * n, buffer, matrix + idx2 * n, n);
		}
	
		*pointer = addition[idx1 * n];
		*pointer2 = matrix[idx1 * n];
		for (idx2 = 0; idx2 < n; idx2++)
		{
			pointer[idx2] /= div;
			pointer2[idx2] /= div;
		}
		//print_matrix(matrix, n, n);
		//print_matrix(addition, n, n);
	}
	}
	return 0;
}
