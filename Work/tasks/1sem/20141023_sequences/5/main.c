#include <stdio.h>
#include "head.h"

int main(void)
{
	const char* name = "a.txt";
	int result;
	result = type_of_sequence(name);
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
		case (0):
		{
			printf("This is Not monotonic sequence\n");
			break;
		}
		case (1):
		{
			printf("This is Icreasing sequence\n");
			break;
		}
		case (2):
		{
			printf("This is Decreasing sequence\n");
			break;
		}
		case (3):
		{
			printf("This is Constant sequence\n");
			break;
		}
		case (4):
		{
			printf("There is not enough data\n");
			break;
		}
		default:
		{
			printf("Unknown error\n");
		}
	}
	return 0;
}
