#include "sort.h"
#include <cstdio>

void find_sort (student_list *head)
{
  student_node *element = 0, *curr = 0, *cur_min = head->get_head();
  for (curr = head->get_head();
       curr;
       curr = curr->get_next())
    {
      cur_min = curr;
      for (element = curr->get_next();
           element;
           element = element->get_next())
        {
          if (*element < *cur_min)
            {
              cur_min = element;
            }
        }
      cur_min->swap (*curr);
    }
  return;
}
