#include <stdio.h>
#include "head.h"

int main(void)
{
	long long result;
	const char* name = "a.txt";
	result = number_of_different_numbers(name);
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
				printf("The Sequence is decreasing\n");
				break;
			}
			default:
			{
				printf("Unknown error\n");
			}
		}
		return 0;
	}
	printf("Number of different numbers in the sequence = %lld\n", result);
	return 0;
}
