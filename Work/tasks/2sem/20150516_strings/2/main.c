#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "head.h"


int main(int argc, char *argv[])
{
	const char *input_file = "a.txt", *output_file = "b.txt";
	int result, idx;
	double counter_of_time;
	
	counter_of_time = clock();
	result = solve(input_file, output_file);
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
	printf("%d comments were founded\n", result);
	printf("Elapsed = %.2lf\n", counter_of_time);
	
	return 0;
}
