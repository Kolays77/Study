#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "read.h"

#define LENGTH 10000

int main(int argc, char *argv[])
{
	const char *input_file = "a.txt", *output_file = "b.txt";
	int result, idx;
	char substr[LENGTH], first[LENGTH], last[LENGTH];
	double counter_of_time;
	
	if (argc != 1)
	{
		printf("Usage: %s filename\n", argv[0]);
		return 0;
	}
	
	printf("Input substring: ");
	if (!fgets(substr, LENGTH, stdin))
	{
		printf("Cannot read substr!\n");
		return 1;
	}
	
	printf("Input first string: ");
	if (!fgets(first, LENGTH, stdin))
	{
		printf("Cannot read first string!\n");
		return 1;
	}
	
	printf("Input last string: ");
	if (!fgets(last, LENGTH, stdin))
	{
		printf("Cannot read last substring!\n");
		return 1;
	}

	make_string(substr);
	make_string(first);
	make_string(last);

	strcat(first, substr);
	strcat(first, last);
	counter_of_time = clock();
	result = solve(input_file, output_file, substr, first);
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
