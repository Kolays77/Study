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
	printf("ARRAY:\n");
	for (idx = 0; idx < m; idx++)
	{
		printf("array[%2d] = %lf\n", idx, array[idx]);
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

void rewrite_array(double *array, int length, double x)
{
	int idx, 
	    idx_first_more = length,
		idx_first_less;
	double elem;
	
	for (idx = 0; idx < length; idx++)
	{
		if (array[idx] > x)
		{
			idx_first_more = idx;
			break;
		}
	}
	
	for (idx_first_less = idx_first_more; idx_first_less < length; idx_first_less++)
	{
		if (array[idx_first_less] > x)
		{
			continue;
		}
		elem = array[idx_first_less];
		array[idx_first_less] = array[idx_first_more];
		array[idx_first_more] = elem;
		idx_first_more++;
	}	
	
	return;	
}
