#include "solve.h"

int number_of_constant_sites (student_list *head)
{
  int count = 0, cur_len = 1;
  student_node *previous = head->get_head(), *element;

  for (element = previous->get_next(); element; previous = element,
                                                element = element->get_next())
    {
      if (*previous != *element)
        {
          if (cur_len > 1)
            {
              count++;
            }
          cur_len = 1;
        }
      else
        {
          cur_len++;
        }
    }
  if (cur_len > 1)
    {
      count++;
    }

  return count;
}
