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

int count(double *array, const char *name, int n)
{
	FILE *fp;
	int cnt = 0, cur_length= 0;
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
	while (fscanf(fp, "%lf", &elem) == 1)
	{
		if (elem == array[cur_length])
		{
			cur_length++;
			if (cur_length != n)
			{
				continue;
			}
			while (cur_length == n)
			{
				cnt++;
				if (fscanf(fp, "%lf", &elem) != 1)
				{
					if (feof(fp))
					{
						fclose(fp);
						return cnt;
					}
					fclose(fp);
					return -2;
				}
				cur_length = find_shift(array, cur_length, elem);
			}
		}
		else
		{
			cur_length = find_shift(array, cur_length, elem);
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

int find_shift(double *array, int cur_length, double elem)
{
	int shift, idx = 0, was_change = 0;
	for (shift = 1; shift <= cur_length; shift++)
	{	
		for (idx = 0; shift + idx < cur_length; idx++)
		{
			if (array[idx] != array[idx + shift])
			{
				break;
			}
		}
		if (idx + shift == cur_length && array[idx] == elem)
		{
			was_change = 1;
			cur_length -= (shift - 1);
			break;
		} 
	}
	if (!was_change)
	{
		return 0;
	}
	return cur_length;
}
