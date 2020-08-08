#include "solve.h"
#include <cstdio>

student_list *delete_6 (student_list *head, student *element, int *n)
{
  student_node *prev = head->get_head(), *curr, *next;
  curr = prev->get_next();
  int need_delete1 = -1, need_delete2 = 0, need_delete_head = 0;
  if (!curr)
    {
      return head;
    }
  next = curr->get_next();
  if (*curr == *element)
    {
      need_delete_head = 1;
    }
  head->set_curr (prev);
  if (!next)
    {
      if (*prev == *element)
        {
          head->delete_next();
        }
      if (need_delete_head)
        {
          head->delete_first();
        }
      return head;
    }
  if (*prev == *element || (next && *next == *element))
    {
      need_delete2 = 1;
    }
  prev = curr;
  curr = next;
  next = next->get_next();
  while (next)
    {
      if (need_delete1 == 1)
        {
          head->delete_next();
          (*n)--;
        }
      else if (need_delete1 != -1)
        {
          head->goto_next();
        }

      need_delete1 = need_delete2;
      need_delete2 = 0;
      if (*prev == *element || *next == *element)
        {
          need_delete2 = 1;
        }
      prev = curr;
      curr = next;
      next = next->get_next();
    }
  if (need_delete1 == 1)
    {
      head->delete_next();
      (*n)--;
    }
  else if (need_delete1 != -1)
    {
      head->goto_next();
    }
  need_delete1 = need_delete2;
  need_delete2 = 0;
  if (*prev == *element)
    {
      need_delete2 = 1;
    }
  if (need_delete1 == 1)
    {
      head->delete_next();
      (*n)--;
    }
  else
    {
      head->goto_next();
    }
  if (need_delete2 == 1)
    {
      head->delete_next();
      (*n)--;
    }
  if (need_delete_head)
    {
      head->delete_first();
      (*n)--;
    }
  return head;
}
