#include <stdio.h>
#include <math.h>
#include "head.h"

const double EPS = 1e-12;

int get_number(double x, const char *name)
{
	FILE *fp;
	double element;
	int cur_idx = 1, idx = 0;
	
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
		idx = cur_idx;
	}
	
	while (fscanf(fp, "%lf", &element) == 1)
	{
		cur_idx++;
		if (fabs(element - x) < EPS)
		{
			idx = cur_idx;
		}
	}
	
	if (!feof(fp))
	{	
		fclose(fp);
		return -2;
	}
	fclose(fp);
	return idx;
}
