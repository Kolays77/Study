#include <stdio.h>
#include "head.h"

const int MAX_PRINTABLE_NUMBER = 30;

int read_array(const char *name, double *array, int n)
{
	FILE *fp;
	int idx;
	if (!(fp = fopen(name, "r")))
	{
		return -1;
	}
	
	for (idx = 0; idx < n; idx++)
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

void return_error(const char *name, int result)
{
	switch (result)
	{
		case (-1):
		{
			printf("Cannot open %s\n", name);
			break;
		}
		case (-2):
		{
			printf("Cannot read %s\n", name);
			break;
		}
		case (-3):
		{
			printf("%s is empty\n", name);
			break;
		}
		default:
		{
			printf("Unknown error %d in %s\n", result, name);
		}
	}	
	return;
} 

void print_array(double *array, int n)
{
	int idx,
	    left_board = (n > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : n),
		right_board = ((n - left_board) > left_board ? n - left_board : left_board);
	printf("ARRAY:\n");
	for (idx = 0; idx < left_board; idx++)
	{
		printf("array[%2d] = %lf\n", idx, array[idx]);
	}
	if (2 * MAX_PRINTABLE_NUMBER < n)
	{
		printf("...\n");
	}
	for (idx = right_board; idx < n; idx++)
	{
		printf("array[%2d] = %lf\n", idx, array[idx]);
	}
	printf("\n");
	return;
}

int comparator(double a, double b)
{
	if (a < b)
	{
		return 1;
	}
	if (a > b)
	{
		return -1;
	}
	return 0;
}

int check_array(double *array,
                int n,
                int (*cmp) (double, double))
{
	int idx;
	for (idx = 1; idx < n; idx++)
	{
		if (cmp(array[idx], array[idx - 1]) == 1)
		{
			return 0; 
		}
	}
	return 1;
}

int merge_union(double *a,
                double *b,
                int len_a,
                int len_b,
                double *result,
                int (*cmp) (double, double))
{
	int idx_a = 0, idx_b = 0, count_equal = 0;
	while (idx_a != len_a && idx_b != len_b)
	{
		if (cmp(a[idx_a], b[idx_b]) == 1)
		{
			result[idx_a + idx_b - count_equal] = a[idx_a];
			idx_a++;
			continue;
		}
		if (cmp(a[idx_a], b[idx_b]) == -1)
		{
			result[idx_a + idx_b - count_equal] = b[idx_b];
			idx_b++;
			continue;
		}
		result[idx_a + idx_b - count_equal] = b[idx_b];
		idx_b++;
		idx_a++;
		count_equal++;
	}
	for (; idx_a < len_a; idx_a++)
	{
		result[idx_a + idx_b - count_equal] = a[idx_a];
	}
	for (; idx_b < len_b; idx_b++)
	{
		result[idx_a + idx_b - count_equal] = b[idx_b];
	}
	return len_a + len_b - count_equal;
}
