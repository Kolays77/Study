#include "sort.h"
#include <cstdio>

void bubble_sort (student_list *head, int n)
{
  student_node *element = 0, *curr = 0, *next = 0;
  int idx1, idx2;
  for (curr = head->get_head(), idx1 = 0;
       curr;
       curr = curr->get_next(), idx1++)
    {
      for (element = head->get_head(), next = element->get_next(), idx2 = 0;
           idx2 < n - idx1 - 1;
           element = next, next = next->get_next(), idx2++)
        {
          if (*next < *element)
            {
              next->swap (*element);
            }
        }
    }

  return;
}
