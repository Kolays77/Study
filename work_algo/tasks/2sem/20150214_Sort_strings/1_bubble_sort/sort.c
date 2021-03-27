#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int comparator(const char *a,
			   const char *b)
{
	return strcmp(a, b) < 0;
}

void bubble_sort(char **array,
                 int length,
                 int (*cmp)(const char *, const char *))
{
	int idx, cur_length, max_length = length - 1;
	char *element;
	for (cur_length = max_length; cur_length > 0; cur_length--)
	{
		for (idx = 0; idx < cur_length; idx++)
		{
			if (!cmp(array[idx], array[idx + 1]))
			{
				element = array[idx];
				array[idx] = array[idx + 1];
				array[idx + 1] = element;
			}
		}
	}
	return;
}
