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
	return a < b;
}

void binary_insertion_sort(double *array,
						   int length,
						   int (*cmp)(double, double))
{
	int insert_idx, idx, current_length;
	double element;
	for (current_length = 1; current_length < length; current_length++)
	{
		element = array[current_length];
		insert_idx = binsearch(array, current_length, element, cmp);
		for (idx = current_length; idx > insert_idx; idx--)
		{
			array[idx] = array[idx - 1];
		}
		array[insert_idx] = element;	
	}
	return;
}


int binsearch(double *array,
			  int length,
			  double new_element,
			  int (*cmp)(double, double))
{
	int left = 0, right = length, middle;
	while (right != left)
	{
		middle = (left + right) / 2;
		if (cmp(array[middle], new_element))
		{
			left = middle + 1;
		}
		else
		{
			right = middle;
		}
	} 
	return left;
}
