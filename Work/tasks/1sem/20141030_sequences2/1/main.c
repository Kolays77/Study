#include <stdio.h>
#include "head.h"

int main(void)
{
	const char *name = "a.txt";
	double d = 0;
	int result = count_deviation(name, &d);
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
			printf("%s is empty\n", name);
			break;
		}
		case (1):
		{
			printf("Mean deviation = %lf\n", d);
			break;
		}
		default:
		{
			printf("Unknown Error\n");
		}
	}
	return 0;
}
