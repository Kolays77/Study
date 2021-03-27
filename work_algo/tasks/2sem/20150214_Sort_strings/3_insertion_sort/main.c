#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "read.h"
#include "sort.h"

int main(int argc, char **argv)
{
	const char *name = "a.txt";
	int n, result, idx;
	char **array;
	double counter_of_time;
	int (*ptr)(const char *, const char *);
	
	if (argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		return 0;
	}
	
	ptr = &comparator;
	
	if (sscanf(argv[1], "%d", &n) != 1)
	{
		printf("Cannot read n!\n");
		return 1;
	}
	
	if (n <= 0)
	{
		printf("n must be more than 0!\n");
		return 1;
	}
	
	if (!(array = (char **) malloc(n * sizeof(char *))))
	{
		printf("Not enough memory!\n");
		return 2;
	}
	
	result = read_array(name, array, n);
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
				printf("Cannot allocate string!\n");
				break;
			}
			default:
			{
				printf("Unknown Error %d in %s!\n", result, name);
			}
		}
		free(array);
		return -1;			
	}
	n = result;
	
	print_array(array, n);
	counter_of_time = clock();
	insertion_sort(array, n, ptr);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	print_array(array, n);
	printf("Elapsed = %.3lf\n", counter_of_time);
	
	for (idx = 0; idx < result; idx++)
	{
		free(array[idx]);
	}
	free(array);
	
	return 0;
}
