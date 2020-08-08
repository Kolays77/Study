#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "head.h"

const double EPS = 1e-12;

int check(const char *name)
{
	FILE *fp;
	double prev, elem, next;
	bool arithmetic = 1, geometric = 1;
	
	if (!(fp = fopen(name, "r")))
	{
		return -1;
	}
	
	if (!(fscanf(fp, "%lf", &prev) == 1))
	{
		if (!feof(fp))
		{
			fclose(fp);
			return -2;
		}
		fclose(fp);
		return -3;
	}
	if (!(fscanf(fp, "%lf %lf", &elem, &next) == 2))
	{	
		if (!feof(fp))
		{
			fclose(fp);
			return -2;
		}
		fclose(fp);
		return 4;
	}
	
	if (fabs((prev + next) - 2 * elem) > EPS)
	{
		arithmetic = 0;
	}
	if (fabs(prev * next - elem * elem) > EPS || elem < 0)
	{
		geometric = 0;
	}
	
	prev = elem;
	elem = next;
	
	while (fscanf(fp, "%lf", &next) == 1)
	{
		if (fabs((prev + next) - 2 * elem) > EPS)
		{
			arithmetic = 0;
		}
		if (fabs(prev * next - elem * elem) > EPS || elem < 0)
		{
			geometric = 0;
		}
		prev = elem;
		elem = next;
	}
	
	if (!feof(fp))
	{	
		fclose(fp);
		return -2;
	}
	
	fclose(fp);
	if (arithmetic && geometric)
	{
		return 3;
	}
	if (arithmetic)
	{
		return 1;
	}
	if (geometric)
	{
		return 2;
	}
	return 0;
}
