#include <stdio.h>
#include "head.h"

int binsearch(double *array, int length, double new_element)
{
	int left = 0, right = length, middle;
	while (right != left)
	{
		middle = (left + right) / 2;
		if (array[middle] < new_element)
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
