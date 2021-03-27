#include "solve.h"
#include <cstdio>

student_list *delete_equal3 (student_list *head, int *n)
{
  student_node *curr = head->get_head(), *next;
  next = curr->get_next();
  if (!next)
    {
      return head;
    }
  head->set_curr (curr);
  while (next)
    {
      while (next && *curr == *next)
        {
          head->delete_next();
          next = curr->get_next();
          (*n)--;
        }
      if (next)
        {
          next = next->get_next();
        }
      curr = next;

      head->goto_next();
    }
  return head;
}
