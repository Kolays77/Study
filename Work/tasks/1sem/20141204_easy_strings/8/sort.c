#include <stdio.h>
#include "head.h"

int comparator(char a, char b)
{
	return a < b;
}

void heapsorted(char *array,
                int length,
                int (*cmp) (char, char))
{
	int idx, current_length;
	for (idx = 1; idx < length; idx++)
	{
		sift_up(array, idx, cmp);
	}
	for (current_length = length - 1; current_length > 0; current_length--)
	{
		swap(&array[0], &array[current_length]);
		sift_down(array, 0, current_length, cmp);
	}
	
}

void sift_up(char *binary_tree, 
		     int position,
		     int (*cmp) (char, char))
{
	char parent, element = binary_tree[position];
	while (position != 0)
	{
		parent = binary_tree[(position - 1) / 2];
		if (!cmp(element, parent))
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

void sift_down(char *binary_tree,
               int position, 
               int length,
               int (*cmp) (char, char))
{
	char element = binary_tree[position];
	while (position * 2 + 1 < length)
	{
		if (position * 2 + 2 < length && 
			cmp(binary_tree[position * 2 + 1], binary_tree[position * 2 + 2]) &&
			cmp(element, binary_tree[position * 2 + 2]))
		{
			binary_tree[position] = binary_tree[position * 2 + 2];
			position *= 2;
			position += 2;
			continue;
		}
		if (cmp(element, binary_tree[position * 2 + 1]))
		{
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

void swap(char *a, char *b)
{
	char element = *a;
	*a = *b;
	*b = element;
	return;
}
