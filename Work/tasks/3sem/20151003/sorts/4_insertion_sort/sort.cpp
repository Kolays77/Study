#include "sort.h"
#include <cstdio>

void insertion_sort (student_list *head)
{
  student_node *element = 0, *cur_finish = 0, *cur_finish_prev = head->get_head(), *element_prev = 0,
      *cur_insert = head->get_head(), *cur_insert_prev = head->get_head();
  for (cur_finish = head->get_head()->get_next(),
       cur_finish_prev = head->get_head();
       cur_finish;
       cur_finish_prev = cur_finish,
       cur_finish = cur_finish->get_next())
    {
      cur_insert = cur_finish;
      cur_insert_prev = cur_finish_prev;

      for (element = head->get_head(),
           element_prev = NULL;
           element != cur_finish;
           element_prev = element,
           element = element->get_next())
        {
          if (*element > *cur_finish)
            {
              cur_insert = element;
              cur_insert_prev = element_prev;
              break;
            }
        }
      element = cur_finish;
      if (cur_insert == cur_finish)
        {
          continue;
        }
      if (!(cur_finish->get_next()))
        {
          cur_finish_prev->set_next (NULL);
        }
      else
        {
          cur_finish_prev->set_next (cur_finish->get_next());
        }

      element->set_next (cur_insert);
      if (cur_insert == head->get_head())
        {
          head->set_head (element);
        }
      else
        {
          cur_insert_prev->set_next (element);
        }
    }
  return;
}
