#include <stdio.h>
#include "head.h"

int main(void)
{
	const char *name = "a.txt";
	int result;
	double x;
	printf("x = ");
	if (!scanf("%lf", &x))
	{
		printf("Input Error\n");
		return 0;
	}
	result = get_number(x, name);
	if (result < 0)
	{
		switch (result)
		{
			case (-1):
			{
				printf("Can not open %s\n", name);
				return 0;
			}
			case (-2):
			{
				printf("Can not read %s\n", name);
				return 0;
			}
			case (-3):
			{
				printf("%s is empty\n", name);
				return 0;
			}
			default:
			{
				printf("Unknown Error\n");
				return 0;
			}
		}
	}
	if (result > 0)
	{
		printf("The index of the 1st element equal to x is %d\n", result);
		return 0;
	}
	printf("There is no element equal to x in %s\n", name);
	return 0;
}
