#include <stdio.h>
#include "head.h"

int main(void)
{
	const char* name = "a.txt";
	long long result;
	result = number_of_max_elements(name);
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
			default:
			{
				printf("Unknown error\n");
			}
		}
		return 0;
	}
	printf("Number of maximum elements = %lld\n", result);
	return 0;
}
