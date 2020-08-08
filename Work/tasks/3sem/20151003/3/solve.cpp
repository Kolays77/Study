#include "solve.h"

int count_elements (student_list *head)
{
  student_node *curr, *previous = head->get_head();
  int count = 0;

  for (curr = previous->get_next(); curr; previous = curr, curr = curr->get_next())
    {
      if (*previous < *curr)
        {
          count++;
        }
    }
  return count;
}
