#include "solve.h"

int get_max_length_of_increase (student_list *head)
{
  int max_length = 1, cur_length = 1;
  student_node *previous = head->get_head(), *element;

  for (element = previous->get_next(); element; previous = element,
                                                element = element->get_next())
    {
      if (*previous < *element)
        {
          cur_length++;
        }
      else
        {
          if (max_length < cur_length)
            {
              max_length = cur_length;
            }
          cur_length = 1;
        }
    }
  if (max_length < cur_length)
    {
      max_length = cur_length;
    }

  return max_length;
}
