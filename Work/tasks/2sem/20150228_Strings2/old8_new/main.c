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
	char str[LENGTH];
	double counter_of_time;
	
	if (argc != 1)
	{
		printf("Usage: %s filename\n", argv[0]);
		return 0;
	}
	printf("Input string: ");
	if (!fgets(str, LENGTH, stdin))
	{
		printf("Cannot read str!\n");
		return 1;
	}
	counter_of_time = clock();
	result = solve(input_file, output_file, str);
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
			case (-3):
			{
				printf("Not enough memory!\n");
				break;	
			}
			case (-4):
			{
				printf("String %s incorrect!\n", str);
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
	printf("%d strings were written\n", result);
	printf("Elapsed = %.2lf\n", counter_of_time);
	
	return 0;
}
