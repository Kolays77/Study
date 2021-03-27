#include <stdio.h>
#include <math.h>
#include "head.h"

const double EPS = 1e-12;

int get_num_of_max(const char *name, double *x)
{
	FILE *fp;
	double element;
	int num = 0;
	
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
	num = 1;
	
	while (fscanf(fp, "%lf", &element) == 1)
	{
		if (fabs(element - *x) < EPS)
		{
			num++;
		}
		if (element > *x)
		{
			*x = element;
			num = 1;
		}
	}
	
	if (!feof(fp))
	{	
		fclose(fp);
		return -2;
	}
	fclose(fp);
	return num;
}
