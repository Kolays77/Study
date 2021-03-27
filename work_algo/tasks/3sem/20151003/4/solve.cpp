#include "solve.h"

int count_local_maximums (student_list *head)
{
  student_node *previous = head->get_head(),
      *curr = previous->get_next(),
      *next;
  int count = 0;

  if (*curr < *previous)
    {
      count++;
    }
  for (next = curr->get_next(); next; previous = curr, curr = next, next = next->get_next())
    {
      if (*previous < *curr && *next < *curr)
        {
          count++;
        }
    }
  if (*previous < *curr)
    {
      count++;
    }
  return count;
}
