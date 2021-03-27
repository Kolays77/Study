#include <stdio.h>
#include <math.h>
#include "head.h"

const int MAX_PRINTABLE_NUMBER = 30;
const double EPS = 1e-12;

void print_array(double *array, int n)
{
	int idx, m = (n > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : n);
	printf("ARRAY:\n");
	for (idx = 0; idx <	 m; idx++)
	{
		printf("a[%d] = %.2lf\n", idx, array[idx]);
	}
	return;
}

int fill_array(const char *name, double *array, int n)
{
	FILE *fp;
	double element;
	if (!(fp = fopen(name, "r")))
	{
		return -1;
	}
	while (fscanf(fp, "%lf", &element) == 1)
	{
		n = binsearch(array, element, n);
	}
	if (!feof(fp))
	{
		fclose(fp);
		return -2;
	}
	fclose(fp);
	return n;
}

int binsearch(double *array, double element, int n)
{
	int left = -1, right = n, middle = (n - 1) / 2, idx;
	while (right - left != 1)
	{
		middle = (right - left) / 2 + left; 
		if (array[middle] < element)
		{
			right = middle;
		}
		else
		{
			left = middle;
		}
	}
	if (fabs(array[left] - element) < EPS)
	{
		return n;
	}
	for (idx = n; idx > right; idx--)
	{
		array[idx] = array[idx - 1];
	}
	array[right] = element;
	n++;
	return n;
}
