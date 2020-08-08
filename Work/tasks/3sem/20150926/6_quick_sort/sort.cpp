#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "read.h"
#include "student.h"

void quick_sort (student *array,
                 int length)
{
  student *element;
  int left_idx = 0, right_idx = length - 1;
  if (length <= 1)
    {
      return;
    }

  while (length > 1)
    {
      left_idx = 0;
      right_idx = length - 1;

      element = array + (length / 2);
      while (left_idx <= right_idx)
        {
          while (left_idx < length)
            {
              if ((array[left_idx] < element[0]) != 1)
                {
                  break;
                }
              else
                {
                  left_idx++;
                }
            }
          while (right_idx >= 0)
            {
              if ((array[right_idx] < element[0]) != -1)
                {
                  break;
                }
              else
                {
                  right_idx--;
                }
            }
          if (left_idx <= right_idx)
            {
              array[left_idx].swap (array[right_idx]);
              left_idx++;
              right_idx--;
            }
        }
      if (left_idx < length - left_idx)
        {
          if (left_idx == 0)
            {
              return;
            }
          quick_sort (array, left_idx);
          array = array + left_idx;
          length = length - left_idx;
        }
      else
        {
          if (length - left_idx == 0)
            {
              return;
            }
          quick_sort (array + left_idx, length - left_idx);
          length = left_idx;
        }
    }
  return;
}
