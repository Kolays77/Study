#include "sort.h"
#include <cstdio>

void find_sort (student_list *head, int n)
{
  student_node *element = 0, *cur_max = head->get_head();
  int idx1 = 0, idx2 = 0;
  for (idx1 = 0; idx1 < n; idx1++)
    {
      cur_max = head->get_head();
      for (element = head->get_head(), idx2 = 0;
           idx2 < n - idx1;
           idx2++)
        {
          if (*element > *cur_max)
            {
              cur_max = element;
            }
          if (idx2 < n - idx1 - 1)
            element = element->get_next();
        }
      cur_max->swap (*element);
    }
  return;
}
