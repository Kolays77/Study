#include <stdio.h>
#include "head.h"

int main(void)
{
	const char* name = "a.txt";
	int check = reverse_fibonachi(name);
	switch (check)
	{
		case (-2):
		{
			printf("Cannot read %s\n", name);
			break;
		}
		case (-1):
		{
			printf("Cannot open %s\n", name);
			break;
		}
		case (0):
		{
			printf("This is not reverse fibonachi sequence\n");
			break;
		}
		case (1):
		{
			printf("This is reverse fibonachi sequence\n");
			break;
		}
		case (2):
		{
			printf("This is empty sequence\n");
			break;
		}
		default:
		{
			printf("Unknown Error\n");
		}
	}
	return 0;
}
