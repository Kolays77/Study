#include <stdio.h>
#include "head.h"

int main(void)
{
	const char *name = "a.txt";
	int result;
	double x = 0;
	result = get_idx_of_max(name, &x);
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
	printf("Max element is %lf\nThe index of the max element is %d\n", x, result);
	return 0;
}
