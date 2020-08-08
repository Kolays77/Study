#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "read.h"

#define LENGTH 10000

int main(int argc, char *argv[])
{
	const char *input_file = "a.txt", *output_file = "b.txt";
	int result, idx;
	char *str, *sparse;
	double counter_of_time;
	
	if (argc != 3)
	{
		printf("Usage: %s [str] [sparse] filename\n", argv[0]);
		return 0;
	}
	if (!(str = argv[1]))
	{
		printf("Cannot create str\n");
		return 1;
	}
	
	if (!(sparse = argv[2]))
	{
		printf("Cannot create sparse\n");
		return 1;
	}
	counter_of_time = clock();
	make_string(str);
	make_string(sparse);
	result = solve(input_file, output_file, str, sparse);
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
