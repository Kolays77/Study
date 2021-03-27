#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"

int main(void)
{
	int n, key;
	int result;
	double *array;
	double counter_of_time, x;
	const char *name = "a.txt";
	
	printf("Input n: ");
	if (scanf("%d", &n) != 1)
	{
		printf("Input Error\n");
		return -1;
	}
	if (n <= 0)
	{
		printf("n must be more than 0!\n");
		return 1;
	}
	printf("Input key: ");
	if (scanf("%d", &key) != 1)
	{
		printf("Input Error\n");
		return -1;
	}
	
	if (!(array = (double *) malloc(n * sizeof(double))))
	{
		printf("Not enough memory\n");
		return -5;
	} 
	
	if (key == 0)
	{
		result = read_array(name, array, n);
		if (result < 0)
		{
			switch (result)
			{
				case (-1):
				{
					printf("Cannot open %s\n", name);
					break;
				}
				case (-2):
				{
					printf("Cannot read %s\n", name);
					break;
				}
				case (-3):
				{
					printf("%s is empty\n", name);
					break;
				}
				default:
				{
					printf("Unknown error %d in %s\n", result, name);
				}
			}
			free(array);
			return -1;
		}
		n = result;
	}
	else
	{
		init_array(array, n, key);
	}
	
	print_array(array, n);
	
	printf("Input x: "); 
	if (scanf("%lf", &x) != 1)
	{
		printf("Input Error!\n");
		free(array);
		return -1;
	}
	counter_of_time = clock();
	n = rewrite_array(array, n, x);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	printf("NEW "); print_array(array, n);
	printf("Elapsed = %.2lf\n", counter_of_time);
	free(array);
	return 0;
}
