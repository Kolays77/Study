#include <stdio.h>
#include "head.h"

long long number_of_different_numbers(const char* name)
{
	FILE *fp;
	long long cnt = 0;
	double data, previous;
	if (!(fp = fopen(name, "r")))
	{
		return -1;
	}
	if (fscanf(fp, "%lf", &previous) == 1)
	{
		cnt++;
	}
	while (fscanf(fp, "%lf", &data) == 1)
	{
		if (data < previous)
		{
			fclose(fp);
			return -3;
		}
		if (data > previous)
		{
			cnt++;
		}
		previous = data;
	}
	if (!feof(fp))
	{
		fclose(fp);
		return -2;
	}
	fclose(fp);
	return cnt;
}
