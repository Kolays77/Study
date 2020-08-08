#include "sort.h"
#include <cstdio>


void quick_sort (student_list *head, student_node *first, student_node *last)
{
  student_node *curr, *first_less, *first_more, *less, *more, *prev;
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
      first_more = more = first;
      length_less = 0;
      length_more = 1;
      if (first != head->get_head())
        {
          prev = first->get_previous();
        }
      for (curr = first->get_next(); curr != last; curr = curr->get_next())
        {
          if (*curr < *first)
            {
              if (!less)
                {
                  first_less = less = curr;
                }
              else
                {
                  less->set_next (curr);
                  curr->set_previous (less);
                  less = curr;
                }
              length_less++;
            }
          else
            {
              more->set_next (curr);
              curr->set_previous (more);
              more = curr;
              length_more++;
            }
        }

      if (first_less)
        {
          more->set_next (last);
          if (last)
            {
              last->set_previous (more);
            }
          else
            {
              head->set_tail (more);
            }
          less->set_next (first_more);
          first_more->set_previous (less);
          if (first == head->get_head())
            {
              head->set_head (first_less);
            }
          else
            {
              prev->set_next (first_less);
              first_less->set_previous (prev);
            }
        }
      else
        {
          first_less = first_more;
          first_more = first_more->get_next();
        }
      if (length_less < length_more)
        {
          quick_sort (head, first_less, first_more);
          first = first_more;
        }
      else
        {
          if (first_more != last && first_more->get_next() != last)
            {
              quick_sort (head, first_more, last);
            }
          last = first_more;
          first = first_less;
        }
    }
  return;
}
