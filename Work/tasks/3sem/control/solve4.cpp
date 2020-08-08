#include "solve.h"
#include <cstdio>
#include <cstring>

student_list *delete_ (student_list *head, char *element, int *n)
{
  student_node *curr = head->get_head(), *next = curr->get_next();
  while (curr && strstr (curr->get_name(), element))
    {
      head->delete_first();
      (*n)--;
      curr = head->get_head();
    }
  if (!curr)
    {
      return head;
    }
  head->set_curr (curr);
  curr = curr->get_next();
  if (curr)
    {
      next = curr->get_next();
    }
  while (curr)
    {
      //printf ("%s %s\n", curr->get_name(), head->get_curr()->get_name());
      if (strstr(curr->get_name(), element))
        {
          head->delete_next();
          (*n)--;
          //next = next->get_next();
        }
      else
        {

          head->goto_next();
        }
      curr = next;
      if (next)
        {
          next = next->get_next();
        }
    }
  return head;
}
