#include <stdio.h>
#include <math.h>
#include "head.h"

const double EPS = 1e-12;

int get_numbers_of_max(const char *name, double *x, int *i, int *j)
{
	FILE *fp;
	double element;
	int cur_idx = 1;
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
	*x = element;
	*i = *j = cur_idx;
	
	while (fscanf(fp, "%lf", &element) == 1)
	{
		cur_idx++;
		if (fabs(element - *x) < EPS)
		{
			*j = cur_idx;
		}
		if (element > *x)
		{
			*x = element;
			*i = *j = cur_idx;
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
