#include "solve.h"
#include <cstdio>

student_list *delete_less2 (student_list *head, int *n)
{
  student_node *prev = head->get_head(), *curr, *next;
  int need_delete1 = 0, need_delete2 = 0;
  curr= prev->get_next();
  if (!curr)
    {
      return head;
    }
  next = curr->get_next();
  if (!next)
    {
      return head;
    }

  head->set_curr (prev);
  if (*curr < *prev && *curr < *next)
    {
      need_delete1 = 1;
    }
  prev = curr;
  curr = next;
  next = next->get_next();

  while (next)
    {
      if (*curr < *prev && *curr < *next)
        {
          need_delete2 = 1;
        }
      prev = curr;
      curr = next;
      next = next->get_next();
      if (need_delete1)
        {
          head->delete_next();
          (*n)--;
        }
      else
        {
          head->goto_next();
        }
      need_delete1 = need_delete2;
      need_delete2 = 0;
    }
  return head;
}
