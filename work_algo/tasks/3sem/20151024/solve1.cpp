#include "solve.h"
#include <cstdio>

student_list *make_new_list1 (student_list *head, student *element, int *n)
{
  student_node *curr = head->get_head();
  head->goto_head();
  while (curr)
    {
      if (*curr > *element)
        {
          (*n)--;
          if (curr == head->get_head())
            {
              head->delete_first();
              if (head->get_head())
                {
                  curr = head->get_head();
                  head->goto_head();
                }
              else
                {
                  return head;
                }
              continue;
            }
          head->delete_next();
          curr = head->get_curr()->get_next();
          continue;
        }
      if (curr && curr != head->get_head())
        {
          head->goto_next();
        }
      curr = curr->get_next();
    }
  return head;
}

