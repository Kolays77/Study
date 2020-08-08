#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include "time.h"

const int MAX_PRINTABLE_NUMBER = 15;

int read_array(const char *name, double *a, double *b, int length)
{
	FILE *fp;
	int idx;
	
	if (!(fp = fopen(name, "r")))
	{
		return -1;
	}
	if (fscanf(fp, "%lf", a) != 1)
	{
		fclose(fp);
		return -3;
	}
	rewind(fp);
	for (idx = 0; idx < length; idx++)
	{
		if (fscanf(fp, "%lf %lf", a + idx, b + idx) != 2)
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
			printf("The number of segments in %s is less than n\nNumber of segments is %d\n", name, idx);
			return idx;
		}
	}
	fclose(fp);
	return idx;
}

void print_segments(double *a, double *b, int n)
{
	int idx,
	    left_board = (n > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : n),
		right_board = ((n - left_board) > left_board ? n - left_board : left_board);
	printf("ARRAY:\n");
	for (idx = 0; idx < left_board; idx++)
	{
		printf("segment[%2d] = [%lf; %lf]\n", idx, a[idx], b[idx]);
	}
	if (2 * MAX_PRINTABLE_NUMBER < n)
	{
		printf("...\n");
	}
	for (idx = right_board; idx < n; idx++)
	{
		printf("segment[%2d] = [%lf; %lf]\n", idx, a[idx], b[idx]);
	}
	printf("\n");
	return;
}

int union_of_segments(double *a, double *b, int n, double *x, double *y)
{
	int idx;
	*x = a[0]; *y = b[0];
	for (idx = 1; idx < n; idx++)
	{
		if (max(*x, a[idx]) > min(*y, b[idx]))
		{
			return 0;
		}
		*x = min(a[idx], *x);
		*y = max(b[idx], *y);
	}
	return 1;
}

double max(double a, double b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

double min(double a, double b)
{
	if (a > b)
	{
		return b;
	}
	return a;
}
