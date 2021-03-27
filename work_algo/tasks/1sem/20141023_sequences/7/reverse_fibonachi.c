#include <stdio.h>
#include "head.h"

int reverse_fibonachi(const char* name)
{
	FILE* fp;
	long long elem1 = -1, elem2 = -1, fib = -1;
	if (!(fp = fopen(name, "r"))) 
	{
		return -1;
	}
	if (!(fscanf(fp, "%lld %lld", &elem1, &elem2) == 2))
	{
		if (elem1 == -1 && elem2 == -1)
		{
			fclose(fp);
			return 2;
		}
		if (elem1 == 1 && elem2 == -1)
		{
			fclose(fp);
			return 1;
		}
	}
	fib = elem1 - elem2;
	elem1 = elem2;
	while (fscanf(fp, "%lld", &elem2) == 1)
	{
		if (elem2 != fib && fib >= 0)
		{
			fclose(fp);
			return 0;
		}
		fib = elem1 - elem2;
		elem1 = elem2;		
	}
	if (!feof(fp))
	{
		fclose(fp);
		return -2;
	}
	fclose(fp);
	if (elem1 == 1 && elem2 == 1 && fib == 0)
	{
		return 1;
	}
	return 0;
}
