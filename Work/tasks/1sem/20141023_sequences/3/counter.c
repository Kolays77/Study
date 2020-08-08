#include <stdio.h>
#include "head.h"

long long counter(const char* name)
{
	FILE *fp;
	long long count = 0;
	double element, previous;
	if (!(fp = fopen(name, "r")))
	{
		return -1;
	}
	if (!(fscanf(fp, "%lf", &previous) == 1))
	{
		fclose(fp);
		return -4;
	}
	while (fscanf(fp, "%lf", &element) == 1)
	{
		if (element > previous)
		{
			count++;
		}
		previous = element;
	}
	if (!feof(fp))
	{
		fclose(fp);
		return -2;
	}
	fclose(fp);
	return count;
}
