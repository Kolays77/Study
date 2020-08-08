#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "read.h"
#include "head.h"

int main(int argc, char **argv)
{
	char *name = "a.txt";
	int n, m, i, j, result;
	double *matrix;
	double counter_of_time, b;
	
	if ((argc != 7) && (argc != 6))
		{
		printf("Usage: %s [m] [n] [i] [j] [<file>]\n", argv[0]);
		return 1;
	}
	if ((m = atoi(argv[1])) <= 0)
	{
		printf("Cannot read [m]!\n");
		return 1;
	}
	if ((n = atoi(argv[2])) <= 0)
	{
		printf("Cannot read [n]!\n");
		return 1;
	}
	if ((i = atoi(argv[3])) <= 0)
	{
		printf("Cannot read [i]!\n");
		return 1;
	}
	if ((j = atoi(argv[4])) <= 0)
	{
		printf("Cannot read [j]!\n");
		return 1;
	}
	if ((b = atof(argv[5])) <= 0)
	{
		printf("Cannot read [b]!\n");
		return 1;
	}
	
	if (argc == 7)
	{
		name = argv[6];
	}
	
	if (!(matrix = (double *) malloc(n * m * sizeof(double))))
	{
		printf("Not enough memory!\n");
		return 2;
	}
	
	if (argc == 7)
	{
		result = read_matrix(name, matrix, n, m);
		if (result < 0)
		{
			switch (result)
			{
				case (-1):
				{
					printf("Cannot open %s!\n", name);
					break;
				}
				case (-2):
				{
					printf("Cannot read %s!\n", name);
					break;
				}
				case (-3):
				{
					printf("%s is empty!\n", name);
					break;
				}
				case (-4):
				{
					printf("Not enough elements in %s!\n", name);
					break;
				}
				default:
				{
					printf("Unknown Error %d in %s!\n", result, name);
				}
			}
			free(matrix);
			return 3;			
		}
	}
	else
	{
		init_matrix(matrix, n, m);
	}
	
	print_matrix(matrix, n, m);
	counter_of_time = clock();
	if (!first_type(matrix, n, m, i, j, b))
	{
		printf("Wrong data!\n");
		return 0;
	}
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	print_matrix(matrix, n, m);
	printf("Elapsed = %.2f\n", counter_of_time);
	free(matrix);
	return 0;
}
