#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"

int main(void)
{
	const char *name = "a.txt";
	int n, result;
	double *a, *b, x = 0;
	double counter_of_time;
	
	printf("Input n: ");
	if (scanf("%d", &n) != 1)
	{
		printf("Input Error!\n");
		return -2;
	}
	if (n <= 0)
	{
		printf("n must be more than 0!\n");
		return 1;
	}
	if (!(a = (double *) malloc(n * sizeof(double))) ||
		!(b = (double *) malloc(n * sizeof(double))))
	{
		printf("Not enough memory!\n");
		return 2;
	}
	
	result = read_array(name, a, b, n);
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
			default:
			{
				printf("Unknown Error %d in %s!\n", result, name);
			}
		}
		free(a); free(b);
		return -1;			
	}
	n = result;
	
	print_segments(a, b, n);
	counter_of_time = clock();
	result = intersection_of_segments(a, b, n, &x);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	if (result == 0)
	{
		printf("There is no point of intersection\n");
	}
	else
	{
		printf("The some point of intersection is %lf\n", x);
	}
	printf("Elapsed = %.2lf\n", counter_of_time);
	free(a); free(b);
	return 0;
}
