#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "read.h"

void merge (student *a,
            student *b,
            int len_a,
            int len_b,
            student *result)
{
  int idx_a = 0, idx_b = 0;
  (void) result;
  while (idx_a != len_a && idx_b != len_b)
    {
      if (a[idx_a] < b[idx_b])
        {
          result[idx_a + idx_b] = a[idx_a];
          idx_a++;
        }
      else
        {
          result[idx_a + idx_b] = b[idx_b];
          idx_b++;
        }
    }
  for (; idx_a < len_a; idx_a++)
    {
      result[idx_a + idx_b] = a[idx_a];
    }
  for (; idx_b < len_b; idx_b++)
    {
      result[idx_a + idx_b]  = b[idx_b];
    }
  return;
}

int merge_sort (student *a,
                student *b,
                int length)
{
  int current_length, idx, current_length1, current_length2, parity = 1;
  for (current_length = 1; current_length < length; current_length *= 2)
    {
      for (idx = 0; idx < length; idx += (2 * current_length))
        {
          current_length2 = current_length1 = current_length;
          if (current_length1 + idx > length)
            {
              current_length1 = length - idx;
              current_length2 = 0;
            }
          if (current_length2 * 2 + idx > length)
            {
              current_length2 = length - idx - current_length;
            }
          if (parity == 1)
            {
              merge (a + idx,
                     a + (idx + current_length),
                     current_length1,
                     current_length2,
                     b + idx);
            }
          else
            {
              merge (b + idx,
                     b + (idx + current_length),
                     current_length1,
                     current_length2,
                     a + idx);
            }
        }
      parity *= (-1);
    }
  return parity;
}
