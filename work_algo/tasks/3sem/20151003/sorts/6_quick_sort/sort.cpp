#include "sort.h"
#include <cstdio>


void quick_sort (student_list *head, student_node *first, student_node *last, student_node *prev_first)
{
  student_node *curr, *first_less, *first_more, *less, *more, *new_prev, *new_prev_first, *curr_prev;
  int length_less = 0, length_more = 0;

  if (!head)
    {
      return;
    }
  if (!first)
    {
      return;
    }
  if (first->get_next() == last)
    {
      return;
    }

  while (first->get_next() != last)
    {
      first_less = less = NULL;
      new_prev = prev_first;
      first_more = more = first;
      length_less = 0;
      length_more = 1;
      for (curr_prev = first, curr = first->get_next(); curr != last; curr_prev = curr, curr = curr->get_next())
        {
          if (*curr < *first)
            {
              if (!less)
                {
                  new_prev_first = curr_prev;
                  first_less = less = curr;
                }
              else
                {
                  less->set_next (curr);
                  less = curr;
                }
              length_less++;
            }
          else
            {
              more->set_next (curr);
              more = curr;
              length_more++;
            }
        }
      if (first_less)
        {
          more->set_next (last);
          less->set_next (first_more);
          new_prev = less;
          if (first == head->get_head())
            {
              head->set_head (first_less);
              new_prev_first = NULL;
            }
          else
            {
              prev_first->set_next (first_less);
              new_prev_first = prev_first;
            }
        }
      else
        {
          new_prev_first = new_prev;
          first_less = first_more;
          new_prev = first_more;
          first_more = first_more->get_next();
        }
      if (length_less < length_more)
        {
          quick_sort (head, first_less, first_more, new_prev_first);
          first = first_more;
          prev_first = new_prev;
        }
      else
        {
          if (first_more != last && first_more->get_next() != last)
            {
              quick_sort (head, first_more, last, new_prev);
            }
          last = first_more;
          first = first_less;
          prev_first = new_prev_first;
        }
    }
  return;
}
