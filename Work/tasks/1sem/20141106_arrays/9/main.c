#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"

int main(void)
{
	int n, key;
	int result, answer;
	double *a, *b;
	double counter_of_time;
	const char *file_array = "a.txt", *file_sequence = "sequence.txt";
	
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
	
	if (!(a = (double *) malloc(n * sizeof(double))))
	{
		printf("Not enough memory\n");
		return -5;
	}
	 
	if (!(b = (double *) malloc(n * sizeof(double))))
	{
		printf("Not enough memory\n");
		return -5;
	} 
	
	if (key == 0)
	{
		result = read_array(file_array, a, n);
		if (result < 0)
		{
			switch (result)
			{
				case (-1):
				{
					printf("Cannot open %s\n", file_array);
					break;
				}
				case (-2):
				{
					printf("Cannot read %s\n", file_array);
					break;
				}
				case (-3):
				{
					printf("%s is empty\n", file_array);
					break;
				}
				default:
				{
					printf("Unknown error %d in %s\n", result, file_array);
				}
			}
			free(a); free(b);
			return -1;
		}
		n = result;
	}
	else
	{
		init_array(a, n, key);
	}
	
	print_array(a, n);
	
	counter_of_time = clock();
	answer = count(a, b, file_sequence, n);
	if (answer < 0)
	{
		switch (answer)
		{
			case (-1):
			{
				printf("Cannot open %s!\n", file_sequence);
				break;
			}
			case (-2):
			{
				printf("Cannot read %s!\n", file_sequence);
				break;
			}
			case (-3):
			{
				printf("%s is empty!\n", file_sequence);
				break;
			}
			default:
			{
				printf("Unknown Error %d in %s!\n", answer, file_sequence);
			}
		}
		free(a); free(b);
		printf("Elapsed = %.2lf\n", counter_of_time);
		return -1;
	}
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	switch (answer)
	{
		case (0):
		{
			printf("There is no array in %s\n", file_sequence); 
			break;
		}
		case (1):
		{
			printf("Array is included once in %s\n", file_sequence);
			break;
		}
		default:
		{
			printf("Array is included %d times in %s\n", answer, file_sequence);
		}
	}
	printf("Elapsed = %.2lf\n", counter_of_time);
	free(a); free(b);
	return 0;
}
