#include "solve.h"
#include <stdio.h>

int count_max_elements (student_list *head)
{
  student_node *curr, *curr_max = head->get_head();
  int count = 0;

  for (curr = head->get_head(); curr; curr = curr->get_next())
    {
      if (*curr_max < *curr)
        {
          curr_max = curr;
          count = 1;
          continue;
        }

      if (!(*curr_max < *curr) && !(*curr < *curr_max))
        {
          count++;
        }
    }
  return count;
}
