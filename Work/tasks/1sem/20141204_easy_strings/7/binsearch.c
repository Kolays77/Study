#include <stdio.h>
#include "head.h"

int binsearch(const char *array, 
              int length,
              char new_element)
{
	int left = 0, right = length, middle;
	while (right != left)
	{
		middle = (left + right) / 2;
		if (array[middle] < new_element)
		{
			left = middle + 1;
			continue;
		}
		if (array[middle] > new_element)
		{
			right = middle;
			continue;
		}
		return 1;
	} 
	if (array[left] == new_element)
	{
		return 1;
	}
	return 0;
}
