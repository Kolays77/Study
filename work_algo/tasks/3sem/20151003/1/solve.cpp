#include "solve.h"

int count_different_elements (student_list *head)
{
  student_node *curr, *to_curr;
  int count = 0;

  for (curr = head->get_head(); curr; curr = curr->get_next())
    {
      for (to_curr = head->get_head(); to_curr != curr; to_curr = to_curr->get_next())
        {
          if (!(*to_curr < *curr) && !(*curr < *to_curr))
            {
              break;
            }
        }
      if (to_curr == curr)
        count++;
    }
  return count;
}
