#include "solve.h"
#include <cstdio>

student_list *make_new_list1 (student_list *head, student *element)
{
  student_node *left = head->get_head(), *right = head->get_tail();
  while (left && right && left->get_previous() != right)
    {
      while (left && (left->get_previous() != right))
        {
          if (*left > *element)
            {
              break;
            }
          else
            {
              left = left->get_next();
            }
        }
      while (right && left && (left->get_previous() != right))
        {
          if (*right < *element)
            {
              break;
            }
          else
            {
              right = right->get_previous();
            }
        }
      if (left && left->get_previous() != right)
        {
          left->swap (*right);
          left = left->get_next();
          right = right->get_previous();
        }
    }
  return head;
}

