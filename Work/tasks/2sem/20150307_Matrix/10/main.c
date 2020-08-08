#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "read_matrix.h"	
#include "head.h"

int main(int argc, char **argv)
{
	char *name1 = "a.txt", *name2 = "v.txt";
	int n, m, k, i, j, result;
	double *matrix1, *matrix2, *answer;
	double counter_of_time, b;
	
	if ((argc != 6) && (argc != 4))
		{
		printf("Usage: %s [n] [m] [k] [<file>] [<file>]\n", argv[0]);
		return 1;
	}
	if ((n = atoi(argv[1])) <= 0)
	{
		printf("Cannot read [n]!\n");
		return 1;
	}
	if ((m = atoi(argv[2])) <= 0)
	{
		printf("Cannot read [m]!\n");
		return 1;
	}
	if ((k = atoi(argv[3])) <= 0)
	{
		printf("Cannot read [k]!\n");
		return 1;
	}
	
	if (argc == 6)
	{
		name1 = argv[4];
		name2 = argv[5];
	}
	
	if (!(matrix1 = (double *) malloc(n * m * sizeof(double))) ||
		!(matrix2 = (double *) malloc(m * k * sizeof(double))) ||
		!(answer = (double *) malloc(n * k * sizeof(double))))
	{
		printf("Not enough memory!\n");
		return 2;
	}
	
	if (argc == 6)
	{
		result = read_matrix(name1, matrix1, n, m);
		if (result < 0)
		{
			return_error(result, name1);
			free(matrix1);
			free(matrix2);
			return 3;			
		}
		result = read_matrix(name2, matrix2, m, k);
		if (result < 0)
		{
			
			free(matrix1);
			free(matrix2);
			return 4;
		}
	}
	else
	{
		init_matrix(matrix1, m, n, 1);
		init_matrix(matrix2, k, m, 2);
	}
	
	printf("1-ST "); print_matrix(matrix1, n, m);
	printf("2-ND "); print_matrix(matrix2, m, k);
	counter_of_time = clock();
	product(matrix1, matrix2, answer, n, m, k);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	printf("PRODUCT "); print_matrix(answer, n, k);
	printf("Elapsed = %.2f\n", counter_of_time);
	free(matrix1);
	free(matrix2);
	return 0;
}
