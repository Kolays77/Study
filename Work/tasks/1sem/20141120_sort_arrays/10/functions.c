#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"

const int MAX_PRINTABLE_NUMBER = 15;

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

void heapsorted(double *array, int length)
{
	int idx, current_length;
	for (idx = 1; idx < length; idx++)
	{
		sift_up(array, idx);
	}
	for (current_length = length - 1; current_length > 0; current_length--)
	{
		swap(&array[0], &array[current_length]);
		sift_down(array, 0, current_length);
		//printf("%d\n", current_length);print_array(array, length);
	}
	
}

void sift_up(double *binary_tree, int position)
{
	double parent, element = binary_tree[position];
	while (position != 0)
	{
		parent = binary_tree[(position - 1) / 2];
		if (element > parent)
		{
			binary_tree[position] = parent;
			position--;
			position /= 2;
		}
		else
		{
			break;
		}
	}
	binary_tree[position] = element;
	return;
}

void sift_down(double *binary_tree, int position, int length)
{
	double element = binary_tree[position];
	//print_array(binary_tree, length);
	while (position * 2 + 1 < length)
	{
		if (position * 2 + 2 < length && 
			binary_tree[position * 2 + 2] > binary_tree[position * 2 + 1] &&
			binary_tree[position * 2 + 2] > element)
		{
		//printf("%.2lf %.2lf\n", binary_tree[position * 2 + 2], element);
			binary_tree[position] = binary_tree[position * 2 + 2];
			position *= 2;
			position += 2;
			continue;
		}
		if (binary_tree[position * 2 + 1] > element)
		{
		//printf("%.2lf %.2lf\n", binary_tree[position * 2 + 1], element);
			binary_tree[position] = binary_tree[position * 2 + 1];
			position *= 2;
			position += 1;
			continue;
		}
		binary_tree[position] = element;
		return;
	}
	binary_tree[position] = element;
	return;
}

void swap(double *a, double *b)
{
	double element = *a;
	*a = *b;
	*b = element;
	return;
}
