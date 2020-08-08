#include "solve.h"
#include <stdio.h>

int max_distance (student_list *head)
{
  int cur_len = 1, max_dist = -1, previous_last = -1, current_first = 0;
  student_node *previous = head->get_head(), *element;

  for (element = previous->get_next(); element; previous = element,
                                                element = element->get_next())
    {
      if (*previous != *element)
        {
          if (cur_len > 1)
            {
              if (previous_last != -1)
                {
                  int cur_dist = current_first - previous_last;
                  if (cur_dist > max_dist)
                    {
                      max_dist = cur_dist;
                    }
                }
              previous_last = cur_len + current_first - 1;
            }
          current_first += cur_len;
          cur_len = 1;
        }
      else
        {
          cur_len++;
        }
    }
  if (cur_len > 1)
    {
      if (previous_last != -1)
        {
          int cur_dist = current_first - previous_last;
          if (cur_dist > max_dist)
            {
              max_dist = cur_dist;
            }
        }
    }

  return max_dist;
}
