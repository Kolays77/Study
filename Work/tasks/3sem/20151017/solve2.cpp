#include "solve.h"
#include <cstdio>

student_list *make_shift2 (student_list *head, int k)
{
  student_node *new_head = 0;
  int idx = 0;
  for (idx = 0, new_head = head->get_head(); idx < k; new_head = new_head->get_next(), idx++)
    {}
  new_head->get_previous()->set_next (NULL);
  head->get_tail()->set_next (head->get_head());
  head->get_head()->set_previous (head->get_tail());
  head->set_tail (head->get_previous());
  new_head->set_previous (NULL);
  head->set_head (new_head);
  return head;
}
