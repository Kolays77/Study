#include "solve.h"
#include <cstdio>

student_list *delete_more4 (student_list *head, student *element, int *n)
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
      while (next && !(*element < *curr))
        {
          curr = next;
          next = next->get_next();
          head->goto_next();
        }
      while (next && *element < *next)
        {
          head->delete_next();
          next = curr->get_next();
          (*n)--;
        }
      curr = next;
      if (next)
        {
          next = next->get_next();
        }

      head->goto_next();
    }
  return head;
}
