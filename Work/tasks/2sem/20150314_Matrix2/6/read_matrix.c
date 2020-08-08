#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "read_matrix.h"

#define MAX_PRINTABLE_NUMBER 5

int read_matrix(const char *name, double *matrix, int n, int m)
{
	FILE *fp;
	int idx1, idx2;
	
	if (!(fp = fopen(name, "r")))
	{
		return -1;
	}
	
	for (idx1 = 0; idx1 < n; idx1++)
	{
		for (idx2 = 0; idx2 < m; idx2++)
		{
			if (fscanf(fp, "%lf", matrix + idx1 * m + idx2) != 1)
			{
				if (!feof(fp))
				{
					fclose(fp);
					return -2;
				}
				fclose(fp);
				if (idx1 == 0 && idx2 == 0)
				{
					return -3;
				}
				return -4;
			}
		}
	}
	fclose(fp);
	return 0;
}

void init_matrix(double *matrix, int n, int m)
{
	int idx1, idx2;
	for (idx1 = 0; idx1 < n; idx1++)
	{
		for (idx2 = 0; idx2 < m; idx2++)
		{
			matrix[idx1 * m + idx2] = init_element(idx1, idx2);
		}
	}
	return;
}

double init_element(int idx1, int idx2)
{
	(void) idx2;
	return (idx1) % 2 + 1;
}

void print_matrix(double *matrix, int n, int m)
{
	int idx1, idx2,
	    left_board1 = (n > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : n),
		right_board1 = ((n - left_board1) > left_board1 ? n - left_board1 : left_board1),
	    left_board2 = (m > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : m),
		right_board2 = ((m - left_board2) > left_board2 ? m - left_board2 : left_board2);
	
	printf("MATRIX:\n     ");
	
	for (idx2 = 0; idx2 < left_board2; idx2++)
	{
		printf("   [%4d]", idx2);
	}
	if (2 * MAX_PRINTABLE_NUMBER < m)
	{
		printf("   ... ");
	}
	for (idx2 = right_board2; idx2 < m; idx2++)
	{
		printf("   [%4d]", idx2);
	}
	printf("\n");
	
	
	for (idx1 = 0; idx1 < left_board1; idx1++)
	{
		printf("[%4d]"	, idx1);
		for (idx2 = 0; idx2 < left_board2; idx2++)
		{
			printf(" %7.2f ", matrix[idx1 * m + idx2]);
		}
		if (2 * MAX_PRINTABLE_NUMBER < m)
		{
			printf("  ...  ");
		}
		for (idx2 = right_board2; idx2 < m; idx2++)
		{
			printf(" %7.2f ", matrix[idx1 * m + idx2]);
		}
		printf("\n");
	}
	
	if (2 * MAX_PRINTABLE_NUMBER < n)
	{
		printf("......................................................................................................\n");
		printf("......................................................................................................\n");
	}
	for (idx1 = right_board1; idx1 < n; idx1++)
	{
		printf("[%4d]", idx1);
		for (idx2 = 0; idx2 < left_board2; idx2++)
		{
			printf(" %7.2f ", matrix[idx1 * m + idx2]);
		}
		if (2 * MAX_PRINTABLE_NUMBER < m)
		{
			printf("  ...  ");
		}
		for (idx2 = right_board2; idx2 < m; idx2++)
		{
			printf(" %7.2f ", matrix[idx1 * m + idx2]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

void return_error(int result, const char *name)
{
	switch (result)
	{
		case (-1):
		{
			printf("Cannot open %s!\n", name);
			break;
		}
		case (-2):
		{
			printf("Cannot read %s!\n", name);
			break;
		}
		case (-3):
		{
			printf("%s is empty!\n", name);
			break;
		}
		case (-4):
		{
			printf("Not enough elements in %s!\n", name);
			break;
		}
		default:
		{
			printf("Unknown Error %d in %s!\n", result, name);
		}
	}
	return;
}
