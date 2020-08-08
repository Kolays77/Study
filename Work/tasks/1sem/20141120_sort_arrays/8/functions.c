#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
void merge(double *a, double *b, int len_a, int len_b, double *result)
{
	int idx_a = 0, idx_b = 0;
	while (idx_a != len_a && idx_b != len_b)
	{
		if (a[idx_a] < b[idx_b])
		{
			result[idx_a + idx_b] = a[idx_a];
			idx_a++;
		}
		else
		{
			result[idx_a + idx_b] = b[idx_b];
			idx_b++;
		}
	}
	for (; idx_a < len_a; idx_a++)
	{
		result[idx_a + idx_b] = a[idx_a];
	}
	for (; idx_b < len_b; idx_b++)
	{
		result[idx_a + idx_b] = b[idx_b];
	}
	return;
}

int merge_sort(double *a, double *b, int length)
{
	int current_length, idx, current_length2, parity = 1;
	for (current_length = 1; current_length < length; current_length *= 2)
	{
		for (idx = 0; idx + current_length <= length; idx += (2 * current_length))
		{
			current_length2 = current_length;
			if (current_length * 2 + idx > length)
			{
				current_length2 = length - idx - current_length;
			}
			if (parity == 1)
			{
				merge(a + idx, a + (idx + current_length), current_length, current_length2, b + idx);
			}
			else
			{
				merge(b + idx, b + (idx + current_length), current_length, current_length2, a + idx);	
			}
		}
		parity *= (-1);
	}
	return parity;
}
