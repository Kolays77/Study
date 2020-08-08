#include "solve.h"
#include <cstdio>

student_list *delete_increasing5 (student_list *head, int *n)
{
  student_node *curr = head->get_head(), *next, *start = 0, *finish = 0;
  next = curr->get_next();
  if (!next)
    {
      return head;
    }
  head->set_curr (curr);
  while (next)
    {
      if (*curr < *next)
        {
          start = curr;
          for (curr = start; next && *curr < *next; curr = next, next = next->get_next())
            {}
          finish = curr;head->set_curr (start);
          for (head->set_curr (start); head->get_curr()->get_next() != finish;)
            {
              head->delete_next();
              (*n)--;
            }
          if (!next)
            {
              return head;
            }
        }
      curr = next;
      next = next->get_next();
    }
  return head;
}
