#include <stdio.h>
#include "head.h"

long long number_of_max_elements(const char* name)
{
	FILE *fp;
	long long count = 0;
	double element, max;
	if (!(fp = fopen(name, "r")))
	{
		return -1;
	}
	if (fscanf(fp, "%lf", &max) == 1)
	{
		count++;
	}
	while (fscanf(fp, "%lf", &element) == 1)
	{
		if (element > max)
		{
			max = element;
			count = 1;
			continue;
		}
		if (element == max)
		{
			count++;
			continue;
		}
	}
	if (!feof(fp))
	{
		fclose(fp);
		return -2;
	}
	fclose(fp);
	return count;
}
