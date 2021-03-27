#include "solve.h"
#include <cstdio>

student_list *delete_increasing (student_list *head, int *n)
{
  student_node *start = 0, *curr = head->get_head()->get_next(), *prev = head->get_head();
  int len_increase = 0;
  for (; curr; prev = curr, curr = curr->get_next())
    {
      if (*prev < *curr)
        {
          if (len_increase == 0)
            {
              start = prev;
            }
          len_increase++;
        }
      else
        {
          if (len_increase == 0)
            {
              continue;
            }
          if (start == head->get_head())
            {
              while (head->get_head() != curr)
                {
                  head->delete_first();
                }
            }
          else
            {
              head->set_curr (start);
              while (head->get_curr() != curr)
                {
                  head->delete_curr();
                  head->goto_next();
                }
            }
          (*n) -= (len_increase + 1);
          len_increase = 0;
        }
    }
  if (len_increase > 0)
    {
      if (start == head->get_head())
        {
          while (head->get_head() != curr)
            {
              head->delete_first();
            }
        }
      else
        {
          head->set_curr (start);
          while (head->get_curr() != curr)
            {
              head->delete_curr();
              head->goto_next();
            }
        }
      (*n) -= (len_increase + 1);
      len_increase = 0;
    }
  return head;
}
