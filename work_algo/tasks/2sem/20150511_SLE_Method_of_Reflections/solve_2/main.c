#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "read_matrix.h"
#include "head.h"

#define MAX_N 25000

int main(int argc, char **argv)
{
	char *name_M = "a.txt";
	int n, idx, max_idx;
	double *matrix, *addition, *vectorX;
	double counter_of_time, residual;
	int result;
	
	if ((argc != 3) && (argc != 2))
	{
		printf("Usage: %s [n] [<file_matrix>]\n", argv[0]);
		return 1;
	}
	if ((n = atoi(argv[1])) <= 0)
	{
		printf("Cannot read [n]!\n");
		return 1;
	}
	if (argc == 3)
	{
		name_M = argv[2];
	}
	
	if (!(matrix = (double *) malloc(n * n * sizeof(double))) ||
		!(addition = (double *) malloc(n * n * sizeof(double))) ||
		!(vectorX = (double *) malloc(n * sizeof(double))))
	{
		printf("Not enough memory!\n");
		return 2;
	}
	if (n > MAX_N)
	{
		printf("Cannot solve!\n");
		return 100;
	}
	if (argc == 3)
	{
		result = read_matrix(name_M, matrix, n);
		if (result < 0)
		{
			return_error(result, name_M);
			free(matrix);
			return 3;			
		}
	}
	else
	{
		init_matrix(matrix, n);
	}
	
	max_idx = n * n;
	for (idx = 0; idx < max_idx; idx += (n + 1))
	{
		addition[idx] = 1;
	}
	print_matrix(matrix, n, n);
	counter_of_time = clock();
	return_matrix(matrix, addition, vectorX, n);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	printf("REVERSE ");
	print_matrix(addition, n, n);
	printf("Elapsed = %.4f\n", counter_of_time);
	
	if (argc == 3)
	{
		result = read_matrix(name_M, matrix, n);
		if (result < 0)
		{
			return_error(result, name_M);
			free(matrix);
			return 3;			
		}
	}
	else
	{
		init_matrix(matrix, n);
	}
	residual = norm_matrix(matrix, addition, n);
	printf("Residual = %e\n", residual);
	free(matrix);
	free(addition);
	free(vectorX);
	return 0;
}
