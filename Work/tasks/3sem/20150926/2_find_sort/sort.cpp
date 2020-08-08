#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "read.h"

void find_sort (student *array,
                int length)
{
  int start_idx, idx, idx_of_current_min;
  if (length < 1)
    return;
  student *current_min;
  for (start_idx = 0; start_idx < length; start_idx++)
    {
      current_min = array + start_idx;
      idx_of_current_min = start_idx;
      for (idx = start_idx + 1; idx < length; idx++)
        {
          if (array[idx] < current_min[0])
            {
              current_min = array + idx;
              idx_of_current_min = idx;
            }
        }
      array[start_idx].swap (array[idx_of_current_min]);
    }
  return;
}
