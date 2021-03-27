#include "solve.h"
#include <cstdio>

student_list *delete_more (student_list *head, int *n)
{
  student_node *next, *curr, *prev;
  head->set_curr(head->get_head());
  int should_delete1 = 0, should_delete2 = 0;
  for (prev = head->get_head(), curr = prev->get_next();
       curr;
       prev = curr,
       curr = curr->get_next(),
       head->goto_next())
    {
      if (should_delete1)
        {
          head->delete_previous();
        }
      next = curr->get_next();
      if (!next)
        {
          break;
        }
      should_delete1 = should_delete2;
      if (*prev < *curr && *curr > *next)
        {
          should_delete2 = 1;
          (*n)--;
        }
      else
        {
          should_delete2 = 0;
        }
    }
  if (should_delete1)
    {
      head->delete_previous();
    }
  head->goto_next();
  if (should_delete2)
    {
      head->delete_previous();
    }
  return head;
}
