#include "sort.h"
#include <cstdio>

student_node *merge (student_node *first, student_node *second, student_node *last)
{
  student_node *new_curr, *curr_first = first, *curr_second = second, *next, *new_head;

  if (*curr_first < *curr_second)
    {
      new_curr = new_head = first;
      curr_first = curr_first->get_next();
    }
  else
    {
      new_curr = new_head = second;
      curr_second = curr_second->get_next();
    }

  while (curr_first != second && curr_second != last)
    {
      if (*curr_first < *curr_second)
        {
          next = curr_first->get_next();
          new_curr->set_next (curr_first);
          curr_first->set_previous (new_curr);
          new_curr = curr_first;
          curr_first = next;
        }
      else
        {
          next = curr_second->get_next();
          new_curr->set_next (curr_second);
          curr_second->set_previous (new_curr);
          new_curr = curr_second;
          curr_second = next;
        }
    }
  if (curr_first != second)
    {
      new_curr->set_next (curr_first);
      curr_first->set_previous (new_curr);
      for (; curr_first->get_next() != second; curr_first = curr_first->get_next());

      curr_first->set_next (last);
      if (last)
        last->set_previous (curr_first);

    }
  else if (curr_second != last)
    {
      new_curr->set_next (curr_second);
      curr_second->set_previous (new_curr);
    }
  return new_head;
}

student_node *get_cur_next (student_node *node, int step)
{
  student_node *curr = node;
  int curr_step;
  for (curr = node, curr_step = 0;
       curr_step < step && curr;
       curr = curr->get_next(), curr_step++);

  if (curr_step < step)
    return 0;
  return curr;
}

void merge_sort (student_list *head)
{
  student_node *first, *second, *last, *new_head, *prev;
  int step = 1;

  if (!head)
    return;
  first = head->get_head();
  if (!first || !first->get_next())
    return;

  while (1)
    {
      prev = 0;
      first = head->get_head();
      second = get_cur_next (first, step);
      if (!second)
        {
          break;
        }

      while (first)
        {
          second = get_cur_next (first, step);
          last = get_cur_next (second, step);
          if (!second)
            {
              break;
            }
          new_head = merge (first, second, last);
          if (!prev)
            {
              head->set_head (new_head);
            }
          else
            {
              prev->set_next (new_head);
              new_head->set_previous (prev);
            }
          if (last != NULL)
            {
              prev = last->get_previous();
            }

          first = last;
        }
      step *= 2;

    }
}
