#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

const double EPS = 1e-12;
const int MAX_PRINTABLE_NUMBER = 30;

int read_array(const char *name, double *array, int max_n)
{
	FILE *fp;
	int idx;
	if (!(fp = fopen(name, "r")))
	{
		return -1;
	}
	for (idx = 0; idx < max_n; idx++)
	{
		if (fscanf(fp, "%lf", array + idx) != 1)
		{
			if (!feof(fp))
			{
				fclose(fp);
				return -2;
			}
			fclose(fp);
			if (idx == 0)
			{
				return -3;
			}
			printf("The number of elements in %s is less than n\nNumber of elements is %d\n", name, idx);
			return idx;
		}
	}
	fclose(fp);
	return idx;	
}

void print_array(double *array, int n)
{
	int idx, m = (n > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : n);
	for (idx = 0; idx < m; idx++)
	{
		printf("array[%d] = %lf\n", idx, array[idx]);
	}
	printf("\n");
	return;
}

void init_array(double *array, int length, int key)
{
	int idx;
	srand(key);
	for (idx = 0; idx < length; idx++)
	{
		array[idx] = rand();
	}
	return;
}

int count(double *a, double *b, const char *name, int n)
{
	FILE *fp;
	int cnt = 0, idx = 0;
	double elem;
	if (!(fp = fopen(name, "r")))
	{
		return -1;
	}
	if (fscanf(fp, "%lf", &elem) != 1)
	{
		fclose(fp);
		return -3;
	}
	rewind(fp);
	while (idx < n - 1 && fscanf(fp, "%lf", &elem) == 1)
	{
		b[idx] = elem;
		idx++;
	}
	while (fscanf(fp, "%lf", &elem) == 1)
	{
		b[n - 1] = elem;
		for (idx = 0; idx < n; idx++)
		{
			if (fabs(a[idx] - b[idx]) > EPS)
			{
				break;
			}
		}
		if (idx == n)
		{
			cnt++;
		}
		
		for (idx = 1; idx < n; idx++)
		{
			b[idx - 1] = b[idx];
		}
	}
	if (!feof(fp))
	{
		fclose(fp);
		return -2;
	}
	fclose(fp);
	return cnt;
}