#include <stdio.h>
#include "head.h"

int main(void)
{
	const char *name = "a.txt";
	int result, i, j;
	double x = 0;
	result = get_numbers_of_max(name, &x, &i, &j);
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
	printf("Max element is %lf\nThe first index of the max element is %d\nThe last index of max number is %d\n", x, i, j);
	return 0;
}
