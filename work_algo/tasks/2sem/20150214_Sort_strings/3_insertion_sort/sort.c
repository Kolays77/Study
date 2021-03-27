#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int comparator(const char *a,
			   const char *b)
{
	return strcmp(a, b) < 0;
}

void insertion_sort(char **array,
               int length,
               int (*cmp)(const char *, const char *))
{
	int finish_idx, idx, idx_insert;
	char *element;
	for (finish_idx = 1; finish_idx < length; finish_idx++)
	{
		idx_insert = finish_idx;
		for (idx = 0; idx < finish_idx; idx++)
		{
			if (!cmp(array[idx], array[finish_idx]))
			{
				idx_insert = idx;
				break;
			}
		}
		element = array[finish_idx];
		for (idx = finish_idx; idx > idx_insert; idx--)
		{
			array[idx] = array[idx - 1];
		}
		array[idx_insert] = element;
	}
	return;
}
