#include "solve.h"
#include <cstdio>

student_list *delete_monotonic (student_list *head, int k, int *n)
{
  student_node *start = 0, *curr = head->get_head()->get_next(), *prev = head->get_head();
  int len_monotonic = 0;
  if (k > *n)
    {
      return head;
    }
  if (k == 1)
    {
      while (head->get_head())
        {
          head->delete_first();
        }
      (*n) = 0;
      return head;
    }
  k--;
  for (; curr; prev = curr, curr = curr->get_next())
    {
      //printf ("%d %d\n", prev->get_value(), curr->get_value());
      if (*prev == *curr)
        {
          if (len_monotonic == 0)
            {
              start = prev;
            }
          len_monotonic++;
        }
      else
        {
          if (len_monotonic < k)
            {
              len_monotonic = 0;
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
          (*n) -= (len_monotonic + 1);
          len_monotonic = 0;
        }
    }
  //printf ("%d %d; len %d\n", prev->get_value(), curr->get_value(), len_monotonic);
  if (len_monotonic > (k - 1))
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
      (*n) -= (len_monotonic + 1);
      len_monotonic = 0;
    }
  return head;
}
