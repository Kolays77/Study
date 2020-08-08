#include "solve.h"
#include <cstdio>

student_list *delete_less (student_list *head, int *n)
{
  student_node *curr, *prev;
  head->set_curr(head->get_head()->get_next());
  for (prev = head->get_head(), curr = head->get_head()->get_next();
       curr;
       prev = curr,
       curr = curr->get_next(),
       head->goto_next())
    {
      if (*prev < *curr)
        {
          head->delete_previous();
          (*n)--;
        }
    }
  return head;
}
