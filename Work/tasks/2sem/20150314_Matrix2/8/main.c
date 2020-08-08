#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "read_matrix.h"
#include "read_vector.h"
#include "head.h"

#define MAX_N 25000

int main(int argc, char **argv)
{
	char *name_M = "a.txt", *name_V1 = "a.txt";
	int n, m, result;
	double *matrix, *vector, vector2[MAX_N];
	double counter_of_time, answer;
	
	if ((argc != 5) && (argc != 3))
		{
		printf("Usage: %s [n] [m] [<file_matrix>] [<file_vector>]\n", argv[0]);
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
	if (argc == 5)
	{
		name_M = argv[3];
		name_V1 = argv[4];
	}
	
	if (!(matrix = (double *) malloc(n * n * sizeof(double))) ||
		!(vector = (double *) malloc(n * sizeof(double))))
	{
		printf("Not enough memory!\n");
		return 2;
	}
	if (n > MAX_N)
	{
		printf("Cannot solve!\n");
		return 100;
	}
	if (argc == 5)
	{
		result = read_matrix(name_M, matrix, n, n);
		if (result < 0)
		{
			return_error(result, name_M);
			free(matrix);
			free(vector);
			return 3;			
		}
		result = read_vector(name_V1, vector, n);
		if (result < 0)
		{
			return_error(result, name_V1);
			free(matrix);
			free(vector);
			return 4;
		}
	}
	else
	{
		init_matrix(matrix, n, n);
		init_vector(vector, n);
	}
	
	print_matrix(matrix, n, n);
	print_vector(vector, n);
	counter_of_time = clock();
	answer = solve(matrix, vector, vector2, n, m);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	printf("ANSWER %.2f\n", answer);
	printf("Elapsed = %.2f\n", counter_of_time);
	free(matrix);
	free(vector);
	return 0;
}
