#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "read_vector.h"

#define MAX_PRINTABLE_NUMBER 5

int read_vector(const char *name, double *vector, int max_n)
{
	FILE *fp;
	int idx;
	if (!(fp = fopen(name, "r")))
	{
		return -1;
	}
	for (idx = 0; idx < max_n; idx++)
	{
		if (fscanf(fp, "%lf", vector + idx) != 1)
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
			return -4;
		}
	}
	fclose(fp);
	return idx;	
}

void print_vector(double *vector, int n)
{
	int idx,
	    left_board = (n > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : n),
		right_board = ((n - left_board) > left_board ? n - left_board : left_board);
	printf("VECTOR:\n      (%7.2f", vector[0]);
	for (idx = 1; idx < left_board; idx++)
	{
		printf(", %7.2f", vector[idx]);
	}
	if (2 * MAX_PRINTABLE_NUMBER < n)
	{
		printf("   ... ");
	}
	for (idx = right_board; idx < n; idx++)
	{
		printf(", %7.2f", vector[idx]);
	}
	printf(")\n\n");
	return;
}

void init_vector(double *vector, int length)
{
	int idx;
	for (idx = 0; idx < length; idx++)
	{
		vector[idx] = init_(idx);
	}
	return;
}

double init_(int idx)
{
	return -idx % 2;
}
