#include <stdio.h>
#include <math.h>
#include "head.h"

const double EPS = 1e-6;

int check(const char* name1, const char* name2)
{
	FILE *fp1, *fp2;
	int i;
	double a_prev, a_cur, a_next, b_cur;
	if (!(fp1 = fopen(name1, "r"))) 
	{
		return -11;
	}
	if (!(fp2 = fopen(name2, "r")))
	{
		return -12;
	}
	
	if (!(fscanf(fp1, "%lf", &a_prev) == 1))
	{	
		if (!feof(fp1))
		{
			fclose(fp1); fclose(fp2);
			return -41;
		}
		fclose(fp1); fclose(fp2);
		return -21;
	}
	
	if (!(fscanf(fp2, "%lf", &b_cur) == 1))
	{	
		if (!feof(fp2))
		{
			fclose(fp1); fclose(fp2);
			return -42;
		}
		fclose(fp1); fclose(fp2);
		return -22;
	}
	
	if (!(fscanf(fp1, "%lf %lf", &a_cur, &a_next) == 2))
	{
		if (!feof(fp1))
		{
			fclose(fp1); fclose(fp2);
			return -41;
		}
		for (i = 0; i < 2; i++)
		{
			if (!(fscanf(fp2, "%lf", &b_cur) == 1))
			{
				if (!feof(fp2))
				{
					fclose(fp1); fclose(fp2);
					return -42;
				}
				fclose(fp1); fclose(fp2);
				return 1;
			}
		}
		fclose(fp1); fclose(fp2);
		return -3;
	}
	
	if (!(fscanf(fp2, "%lf", &b_cur) == 1))
	{
		if (!feof(fp2))
		{
			fclose(fp1); fclose(fp2);
			return -42;
		}
		fclose(fp1); fclose(fp2);
		return 1;
	}
	
	if (fabs((a_prev + a_next) / 2 - b_cur) > EPS)
	{
		fclose(fp1); fclose(fp2);
		return 0;
	}
	a_prev = a_cur;
	a_cur = a_next;
	if (!(fscanf(fp2, "%lf", &b_cur) == 1))
	{
		fclose(fp1); fclose(fp2);
		return 1;
	}
	
	while (fscanf(fp1, "%lf", &a_next) == 1)
	{	
		if (fabs((a_prev + a_next) / 2 - b_cur) > EPS)
		{	
			if (!(fscanf(fp2, "%lf", &b_cur) == 1))
			{
				if (!feof(fp2))
				{
					fclose(fp1); fclose(fp2);
					return -42;
				}
				fclose(fp1); fclose(fp2);
				return 1;
			}
			fclose(fp1); fclose(fp2);
			return 0;
		}
		a_prev = a_cur;
		a_cur = a_next;
	
		if (!(fscanf(fp2, "%lf", &b_cur) == 1))
		{
			if (!feof(fp2))
			{
				fclose(fp1); fclose(fp2);
				return -42;
			}
			fclose(fp1); fclose(fp2);
			return 1;
		}
	}
	if (!feof(fp1))
	{
		fclose(fp1); fclose(fp2);
		return -41;
	}
	if (!(fscanf(fp2, "%lf", &b_cur) == 1))
	{
		fclose(fp1); fclose(fp2);
		return 1;
	}
	fclose(fp1); fclose(fp2);
	return -3;
}
