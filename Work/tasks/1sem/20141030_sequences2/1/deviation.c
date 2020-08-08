#include <stdio.h>
#include <math.h>
#include "head.h"

int count_deviation(const char *name, double* d)
{
	FILE *fp;
	double deviation = 0, arithmetic_mean = 0, element, num = 0;
	if (!(fp = fopen(name, "r")))
	{
		return -1;
	}
	if (!(fscanf(fp, "%lf", &element) ==1))
	{
		if (!feof(fp))
		{
			fclose(fp);
			return -2;
		}
		fclose(fp);
		return -3;
	}
	arithmetic_mean += element;
	num++;
	while (fscanf(fp, "%lf", &element) == 1)
	{
		arithmetic_mean += element;
		num++;
	}
	if (!feof(fp))
	{
		fclose(fp);
		return -2;
	}
	arithmetic_mean /= num;
	fclose(fp);
	fp = fopen(name, "r");
	while (fscanf(fp, "%lf", &element) == 1)
	{
		deviation += (element - arithmetic_mean) * (element - arithmetic_mean); 
	}
	deviation /= num;
	deviation = sqrt(deviation);
	*d = deviation;
	fclose(fp);
	return 1;	
}
