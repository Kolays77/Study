#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "read_matrix.h"
#include "read_vector.h"
#include "head.h"

#define MAX_N 25000

int main(int argc, char **argv)
{
	char *name_M = "a.txt", *name_V1 = "a.txt", *name_V2 = "a.txt";
	int n, m, result;
	double *matrix, *vector, *vectorB, vector_answer[MAX_N], tau;
	double counter_of_time;
	
	if ((argc != 7) && (argc != 4))
		{
		printf("Usage: %s [n] [m] [tau] [<file_matrix>] [<file_vector1>] [<file_vectorB>]\n", argv[0]);
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
	if ((tau = atof(argv[3])) <= 0)
	{
		printf("Cannot read[tau]!\n");
		return 1;
	}
	if (argc == 7)
	{
		name_M = argv[4];
		name_V1 = argv[5];
		name_V2 = argv[6];
	}
	
	if (!(matrix = (double *) malloc(n * n * sizeof(double))) ||
		!(vector = (double *) malloc(n * sizeof(double))) ||
		!(vectorB = (double *) malloc(n * sizeof(double))))
	{
		printf("Not enough memory!\n");
		return 2;
	}
	if (n > MAX_N)
	{
		printf("Cannot solve!\n");
		return 100;
	}
	if (argc == 7)
	{
		result = read_matrix(name_M, matrix, n, n);
		if (result < 0)
		{
			return_error(result, name_M);
			free(matrix);
			free(vector);
			free(vectorB);
			return 3;			
		}
		result = read_vector(name_V1, vector, n);
		if (result < 0)
		{
			return_error(result, name_V1);
			free(matrix);
			free(vector);
			free(vectorB);
			return 4;
		}
		result = read_vector(name_V2, vectorB, n);
		if (result < 0)
		{
			return_error(result, name_V2);
			free(matrix);
			free(vector);
			free(vectorB);
			return 4;
		}
	}
	else
	{
		init_matrix(matrix, n, n);
		init_vector(vector, n);
		init_vector(vectorB, n);
	}
	
	print_matrix(matrix, n, n);
	printf("1 "); print_vector(vector, n);
	printf("2 "); print_vector(vectorB, n);
	if (!check_M(matrix, n))
	{
		printf("The solve is not exist!\n");
		return 0;
	}
	counter_of_time = clock();
	result = solve(matrix, vector, vectorB, n, m, tau, vector_answer);
	if (!result)
	{
		return 1;
	}
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	printf("ANSWER ");
	if (result == 1)
	{
		print_vector(vector_answer, n);
	}
	else
	{
		print_vector(vector, n);
	}
	printf("Elapsed = %.2f\n", counter_of_time);
	free(matrix);
	free(vector);
	free(vectorB);
	return 0;
}
