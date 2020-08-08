#include "solve.h"
#include <cstdio>

student_list *delete_more_k (student_list *head, int k, int *n)
{
  student_node *start = head->get_head(), *curr = head->get_tail(), *previous;
  int idx;
  head->set_curr(curr);
  for (idx = 0, start = head->get_tail();
       idx < k;
       start = start->get_previous(), idx++)
    {}

  for (; start; start = start->get_previous())
    {
      for (previous = start; previous != curr; previous = previous->get_next())
        {
          if (*previous > *curr)
            {
              break;
            }
        }
      if (*previous > *curr)
        {
          curr = curr->get_previous();
          head->goto_previous();
          continue;
        }
      head->delete_curr();
      (*n)--;
      curr = head->get_curr();
    }
  return head;
}
