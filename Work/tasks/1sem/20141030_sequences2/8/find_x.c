#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "head.h"

const double EPS = 1e-12;

int find_x(const char *name, double x, int *i, int *j)
{
	FILE *fp;
	double element;
	int cur_idx = 1;
	bool find = 0;
	if (!(fp = fopen(name, "r")))
	{
		return -1;
	}
	
	if (!(fscanf(fp, "%lf", &element) == 1))
	{
		if (!feof(fp))
		{
			fclose(fp);
			return -2;
		}
		fclose(fp);
		return -3;
	}
	if (fabs(element - x) < EPS)
	{
		*i = *j = cur_idx;
	}
	
	while (fscanf(fp, "%lf", &element) == 1)
	{
		cur_idx++;
		if (fabs(element - x) < EPS)
		{
			if (!find)
			{
				find = 1;
				*i = cur_idx;
			}
			*j = cur_idx;
		}
	}
	
	if (!feof(fp))
	{	
		fclose(fp);
		return -2;
	}
	
	fclose(fp);
	return 0;
}
