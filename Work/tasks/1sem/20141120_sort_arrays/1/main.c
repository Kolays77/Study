#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"

int main(void)
{
	const char *name = "a.txt";
	int n, result;
	double counter_of_time, new_element = 0;
	double *array = 0;
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
	
	if (!(array = (double *) malloc(n * sizeof(double))))
	{
		printf("Not enough memory\n");
		return -4;
	} 
	
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
	print_array(array, n);
	printf("Input x: ");
	if (scanf("%lf", &new_element) != 1)
	{
		printf("Input Error\n");
		return -1;		
	}
	
	if (!check_array(array, n))
	{
		free(array);
		printf("Array is not ordered ascending!\n");
		return -5;
	}
	counter_of_time = clock();
	result = binsearch(array, n, new_element);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	printf("You can insert x into %dth position\n", result);
	printf("Elapsed = %.2lf", counter_of_time);
	free(array);
	return 0;
}
