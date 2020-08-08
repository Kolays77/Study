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
int check_array(double *array, int n)
{
	int idx;
	for (idx = 1; idx < n; idx++)
	{
		if (array[idx - 1] >= array[idx])
		{
			return 0; 
		}
	}
	return 1;
}
