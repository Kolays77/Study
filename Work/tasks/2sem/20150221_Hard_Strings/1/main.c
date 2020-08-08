#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "read.h"

#define LENGTH 10000

int main(int argc, char *argv[])
{
	const char *input_file = "a.txt", *output_file = "b.txt";
	int result, idx;
	char *substr, *new_substr;
	double counter_of_time;
	
	if (argc != 3)
	{
		printf("Usage: %s [substr] [newsubstr] filename\n", argv[0]);
		return 0;
	}
	if (!(substr = argv[1]))
	{
		printf("Cannot create substr\n");
		return 1;
	}
	
	if (!(new_substr = argv[2]))
	{
		printf("Cannot create new_substr\n");
		return 1;
	}

	for (idx = 0; substr[idx]; idx++)
	{
		if (substr[idx] == '\n')
		{
			substr[idx] = 0;
			break;
		}
	}
	
	for (idx = 0; new_substr[idx]; idx++)
	{
		if (new_substr[idx] == '\n')
		{
			new_substr[idx] = 0;
			break;
		}
	}
	counter_of_time = clock();
	result = solve(input_file, output_file, substr, new_substr);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	
	if (result < 0)
	{
		switch (result)
		{
			case (-11):
			{
				printf("Cannot open %s!\n", input_file);
				break;
			}
			case (-12):
			{
				printf("Cannot open %s!\n", output_file);
				break;
			}
			case (-2):
			{
				printf("Cannot read %s!\n", input_file);
				break;
			}
			default:
			{
				printf("Unknown Error %d in %s!\n", result, input_file);
				break;
			}
		}
		return 1;
	}
	printf("%d strings were rewrote\n", result);
	printf("Elapsed = %.2lf\n", counter_of_time);
	
	return 0;
}
