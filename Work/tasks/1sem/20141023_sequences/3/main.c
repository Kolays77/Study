#include <stdio.h>
#include "head.h"

int main(void)
{
	const char* name = "a.txt";
	long long result;
	result = counter(name);
	if (result < 0)
	{
		switch (result)
		{
			case (-4):
			{
				printf("%s is empty\n", name);
				break;
			}
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
	printf("Number of elements more than previous = %lld\n", result);
	return 0;
}
