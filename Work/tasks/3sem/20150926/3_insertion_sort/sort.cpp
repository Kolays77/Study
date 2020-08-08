#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "read.h"

void insertion_sort (student *array,
                     int length)
{
  int finish_idx, idx, idx_insert;
  student element = array[0];
  for (finish_idx = 1; finish_idx < length; finish_idx++)
    {
      idx_insert = finish_idx;
      for (idx = 0; idx < finish_idx; idx++)
        {
          if (array[finish_idx] < array[idx])
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
