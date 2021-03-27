#include <stdio.h>
#include "head.h"

int fibonachi(const char* name)
{
	FILE *fp;
	long long fib1 = 1, fib2 = 1, element = -1;
	if (!(fp = fopen(name, "r")))
	{
		return -1;
	}
	while (fscanf(fp, "%lld", &element) == 1)
	{
		if (element != fib1)
		{
			fclose(fp);
			return 0;
		}
		fib2 = fib1 + fib2;
		fib1 = fib2 - fib1;
	}
	if (!feof(fp))
	{
		fclose(fp);
		return -2;
	}
	fclose(fp);
	if (element == -1)
	{
		return -4;
	}	
	return 1;
}
