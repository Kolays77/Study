#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int comparator(const char *a,
			   const char *b)
{
	return strcmp(a, b) < 0;
}

void binary_insertion_sort(char **array,
               int length,
               int (*cmp)(const char *, const char *))
{
	int insert_idx, idx, current_length;
	char *element;
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

int binsearch(char **array,
			  int length,
			  char *new_element,
			  int (*cmp)(const char *, const char *))
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
