#include <stdio.h>
#include "head.h"

int main(void)
{
	const char* name = "a.txt";
	int result;
	result = fibonachi(name);
	switch (result)
	{
		case (-4):
		{
			printf("This is empty sequence\n");
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
			printf("Sequence is not fibonachi\n");
			break;
		}
		case (1):
		{
			printf("Sequence is fibonachi\n");
			break;
		}
		default:
		{
			printf("Unknown error\n");
		}
	}
	return 0;
}
