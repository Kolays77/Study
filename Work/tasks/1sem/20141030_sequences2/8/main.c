#include <stdio.h>
#include "head.h"

int main(void)
{
	const char *name = "a.txt";
	int result, i = 0, j = 0;
	double x;
	printf("x = ");
	if (!scanf("%lf", &x)) 
	{
		printf("Input Error\n");
		return 0;
	}
	result = find_x(name, x, &i, &j);
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
	if (i == 0)
	{
		printf("There is no element equal to x in %s\n", name);
		return 0;
	}
	printf("The first index of telement equal to x is %d\nThe last index of element equal to x is %d\n", i, j);
	return 0;
}
