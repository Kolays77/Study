#include <stdio.h>
#include "head.h"

int main(void)
{
	const char *name = "a.txt";
	int result = check(name);
	switch (result)
	{
		case (-1):
		{
			printf("Can not open %s\n", name);
			break;
		}
		case (-2):
		{
			printf("Can not read %s\n", name);
			break;
		}
		case (-3):
		{
			printf("%s is empty\n", name);
			break;
		}
		case (1):
		{
			printf("Sequence is arithmetic\n");
			break;
		}
		case (2):
		{
			printf("Sequence is geometric\n");
			break;
		}
		case (3):
		{
			printf("Sequence is monotonic\n");
			break;
		}
		case (4):
		{
			printf("Not enough elements in %s\n", name);
			break;
		}
		case (0):
		{
			printf("Sequence is not arithmetic and not geometric\n");
			break;
		}
		default:
		{
			printf("Unknown Error\n");
		}
	}
	return 0;
}
