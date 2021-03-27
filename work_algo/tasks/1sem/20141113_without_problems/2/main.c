#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"

const int MAX_N = 1e6;

int main(void)
{
	const char *name = "a.txt";
	int n = 0, result;
	double *a;
	double counter_of_time;
	if (!(a = (double *) malloc(MAX_N * sizeof(double))))
	{
		printf("Not enough memory!\n");
		return -2;
	}
	counter_of_time = clock();
	result = fill_array(name, a, n);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
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
			default:
			{
				printf("Unknown Error!\n");
			}
		}
		printf("Elapsed = %.2lf\n", counter_of_time);
		return -1;
	}
	printf("There are %d different elements in %s\n", result, name);
	print_array(a, result);
	printf("Elapsed = %.2lf\n", counter_of_time);
	return 0;
}
