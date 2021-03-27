#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "read.h"

void binary_insertion_sort(student *array,
                           int length)
{
  int insert_idx, idx, current_length;
  student element = array[0];
  for (current_length = 1; current_length < length; current_length++)
    {
      element = array[current_length];
      insert_idx = binsearch (array, current_length, &element);
      for (idx = current_length; idx > insert_idx; idx--)
        {
          array[idx] = array[idx - 1];
        }
      array[insert_idx] = element;
    }
  return;
}

int binsearch(student *array,
	      int length,
	      student *new_element)
{
  int left = 0, right = length, middle;
  while (right != left)
    {
      middle = (left + right) / 2;
      if (array[middle] < *new_element)
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
