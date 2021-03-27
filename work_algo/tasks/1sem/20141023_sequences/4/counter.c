#include <stdio.h>
#include "head.h"

long long counter(const char* name)
{
	FILE *fp;
	long long count = 0;
	double element, previous, next;
	if (!(fp = fopen(name, "r")))
	{
		return -1;
	}
	if (!(fscanf(fp, "%lf", &previous) == 1))
	{
		fclose(fp);
		return -4;
	}
	if (fscanf(fp, "%lf", &element) == 1)
	{
		if (previous > element)
		{
			count++;
		}
	}
	else
	{
		fclose(fp);
		return 1;
	}
	while (fscanf(fp, "%lf", &next) == 1)
	{
		if (element > previous && element > next)
		{
			count++;
		}
		previous = element;
		element = next;
	}
	if (!feof(fp))
	{
		fclose(fp);
		return -2;
	}
	if (element > previous)
	{
		count++;
	}
	fclose(fp);
	return count;
}
