#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int comparator(const char *a,
               const char *b)
{
  if (strcmp(a, b) < 0)
    {
      return 1;
    }
  if (strcmp(a, b) > 0)
    {
      return -1;
    }
  return 0;
}

void quick_sort(char **array,
                int length,
                int (*cmp)(const char *, const char *))
{
  char *element;
  int left_idx = 0, right_idx = length - 1;
  if (length <= 1)
    {
      return;
    }
  while (length > 1)
    {
      left_idx = 0;
      right_idx = length - 1;
      element = array[length / 2];
      while (left_idx <= right_idx)
        {
          while (left_idx < length)
            {
              if (cmp(array[left_idx], element) != 1)
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
              if (cmp(array[right_idx], element) != -1)
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
              swap(&array[left_idx], &array[right_idx]);
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
          quick_sort(array, left_idx, cmp);
          array = array + left_idx;
          length = length - left_idx;
        }
      else
        {
          if (length - left_idx == 0)
            {
              return;
            }
          quick_sort(array + left_idx, length - left_idx, cmp);
          length = left_idx;
        }
    }
  return;
}

void swap(char **a, char **b)
{
  char *c;
  c = *a;
  *a = *b;
  *b = c;
  return;
}
