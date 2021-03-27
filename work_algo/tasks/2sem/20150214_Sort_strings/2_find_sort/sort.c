#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int comparator(const char *a,
			   const char *b)
{
	return strcmp(a, b) < 0;
}

void find_sort(char **array,
               int length,
               int (*cmp)(const char *, const char *))
{
	int start_idx, idx, idx_of_current_min;
	char *current_min, *element;
	for (start_idx = 0; start_idx < length; start_idx++)
	{
		current_min = array[start_idx];
		idx_of_current_min = start_idx;
		for (idx = start_idx + 1; idx < length; idx++)
		{
			if (cmp(array[idx], current_min))
			{
				current_min = array[idx];
				idx_of_current_min = idx;
			}
		}
		element = array[start_idx];
		array[start_idx] = array[idx_of_current_min];
		array[idx_of_current_min] = element; 
	}
	return;
}
