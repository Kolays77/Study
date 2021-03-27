#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "read_matrix.h"
#include "read_vector.h"
#include "head.h"

int main(int argc, char **argv)
{
	char *name_matrix = "a.txt", *name_vector = "v.txt";
	int n, m, i, j, result;
	double *matrix, *vector;
	double counter_of_time, b;
	
	if ((argc != 5) && (argc != 3))
		{
		printf("Usage: %s [n] [m] [<file>] [<file>]\n", argv[0]);
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
		name_matrix = argv[3];
		name_vector = argv[4];
	}
	
	if (!(matrix = (double *) malloc(n * m * sizeof(double))) ||
		!(vector = (double *) malloc(n * sizeof(double))))
	{
		printf("Not enough memory!\n");
		return 2;
	}
	
	if (argc == 5)
	{
		result = read_matrix(name_matrix, matrix, m, n);
		if (result < 0)
		{
			switch (result)
			{
				case (-1):
				{
					printf("Cannot open %s!\n", name_matrix);
					break;
				}
				case (-2):
				{
					printf("Cannot read %s!\n", name_matrix);
					break;
				}
				case (-3):
				{
					printf("%s is empty!\n", name_matrix);
					break;
				}
				case (-4):
				{
					printf("Not enough elements in %s!\n", name_matrix);
					break;
				}
				default:
				{
					printf("Unknown Error %d in %s!\n", result, name_matrix);
				}
			}
			free(matrix);
			free(vector);
			return 3;			
		}
		result = read_vector(name_vector, vector, n);
		if (result < 0)
		{
			switch (result)
			{
				case (-1):
				{
					printf("Cannot open %s\n", name_vector);
					break;
				}
				case (-2):
				{
					printf("Cannot read %s\n", name_vector);
					break;
				}
				case (-3):
				{
					printf("%s is empty\n", name_vector);
					break;
				}
				case (-4):
				{
					printf("Not enough elements in %s\n", name_vector);
					break;
				}
				default:
				{
					printf("Unknown Error %d in %s\n", result, name_vector);
				}
			}
			free(matrix);
			free(vector);
			return 4;
		}
	}
	else
	{
		init_matrix(matrix, m, n);
		init_vector(vector, n);
	}
	
	print_matrix(matrix, m, n);
	print_vector(vector, n);
	counter_of_time = clock();
	product(matrix, vector, n, m);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	printf("PRODUCT "); print_vector(matrix, m);
	printf("Elapsed = %.2f\n", counter_of_time);
	free(matrix);
	return 0;
}
