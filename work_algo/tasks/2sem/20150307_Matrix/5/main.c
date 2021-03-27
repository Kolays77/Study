#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "read.h"
#include "head.h"

int main(int argc, char **argv)
{
	char *name = "a.txt";
	int n, result;
	double *matrix;
	double counter_of_time;
	
	if ((argc != 2) && (argc != 3))
		{
		printf("Usage: %s [n] [<file>]\n", argv[0]);
		return 1;
	}
	if ((n = atoi(argv[1])) <= 0)
	{
		printf("Cannot read [n]!\n");
		return 1;
	}
	
	if (argc == 3)
	{
		name = argv[2];
	}
	
	if (!(matrix = (double *) malloc(n * n * sizeof(double))))
	{
		printf("Not enough memory!\n");
		return 2;
	}
	
	if (argc == 3)
	{
		result = read_matrix(name, matrix, n, n);
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
		init_matrix(matrix, n, n);
	}
	
	print_matrix(matrix, n, n);
	counter_of_time = clock();
	dif_matrix(matrix, n);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	print_matrix(matrix, n, n);
	printf("Elapsed = %.2f\n", counter_of_time);
	free(matrix);
	return 0;
}
