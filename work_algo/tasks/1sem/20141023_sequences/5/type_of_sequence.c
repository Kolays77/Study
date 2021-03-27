#include <stdio.h>
#include <stdbool.h>
#include "head.h"

int type_of_sequence(const char* name)
{
	FILE *fp;
	bool decreasing = 1,
		 increasing = 1,
		 constant = 1;
	double element, previous;
	if (!(fp = fopen(name, "r")))
	{
		return -1;
	}
	if (!(fscanf(fp, "%lf", &previous) == 1))
	{
		if (!feof(fp))
		{
			fclose(fp);
			return -2;
		}
		else 
		{
			fclose(fp);
			return -4;
		}
	}
	while (fscanf(fp, "%lf", &element) == 1)
	{
		if (previous < element)
		{
			decreasing = constant = 0;
		}
		if (previous == element)
		{
			decreasing = increasing = 0;
		}
		if (previous > element)
		{
			increasing = constant = 0;
		}
		previous = element;
	}
	if (!feof(fp))
	{
		fclose(fp);
		return -2;
	}
	fclose(fp);
	if (constant && decreasing && constant)
	{
		return 4;
	}
	if (constant)
	{
		return 3;
	}
	if (decreasing)
	{
		return 2;
	}
	if (increasing)
	{
		return 1;
	}
	return 0;
}
