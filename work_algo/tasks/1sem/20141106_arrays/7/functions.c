#include <stdio.h>
#include <stdlib.h>

const int MAX_PRINTABLE_NUMBER = 15;

int read_array(const char *name, double *array, int length)
{
	FILE *fp;
	int idx;
	
	if (!(fp = fopen(name, "r")))
	{
		return -1;
	}
	
	for (idx = 0; idx < length; idx++)
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

int rewrite_array(double *array, int length, int k)
{
	int idx, max_idx = length - 1;
	double *copy;
	k = k % length;
	if (k < 0)
	{
		k += length;
	}
	if (!(copy = (double *) malloc(k * sizeof(double))))
	{
		return -1;
	}
	for (idx = 0; idx < k; idx++)
	{
		copy[idx] = array[length - k + idx];
	}
	for (idx = max_idx; idx >= k; idx--)
	{
		array[idx] = array[idx - k];
	}
	for (idx = 0; idx < k; idx++)
	{
		array[idx] = copy[idx];
	}
	free(copy);
	return 0;
}
