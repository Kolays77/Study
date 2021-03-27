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

void quick_sort(double *array,
                int length,
                int (*cmp)(double, double))
{
	double element;
	int left_idx = 0, right_idx = length - 1;
	if (length <= 1)
	{
		return;
	}
	while (length > 1)
	{
		left_idx = 0;
		right_idx = length - 1;
		element = array[length / 2];
		while (left_idx <= right_idx)
		{
			while (left_idx < length)
			{
				if (cmp(array[left_idx], element) != 1)
				{
					break;
				}
				else
				{
					left_idx++;
				}
			}
			while (right_idx >= 0)
			{
				if (cmp(array[right_idx], element) != -1)
				{
					break;
				}
				else
				{
					right_idx--;
				}
			}
			if (left_idx <= right_idx)
			{
				swap(&array[left_idx], &array[right_idx]);
				left_idx++;
				right_idx--;
			}
		}
		if (left_idx < length - left_idx)
		{
			if (left_idx == 0)
			{
				return;
			}
			quick_sort(array, left_idx, cmp);
			array = array + left_idx;
			length = length - left_idx;
		}
		else
		{
			if (length - left_idx == 0)
			{
				return;
			}
			quick_sort(array + left_idx, length - left_idx, cmp); 
			length = left_idx;
		}
	}
	return;
}

void swap(double *a, double *b)
{
	double c;
	c = *a;
	*a = *b;
	*b = c;
	return;
}
