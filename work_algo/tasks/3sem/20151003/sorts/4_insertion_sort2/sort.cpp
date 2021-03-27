#include "sort.h"

void insertion_sort (student_list *head)
{
  student_node *element = 0, *cur_finish = 0, *cur_insert = head->get_head();
  for (cur_finish = head->get_head()->get_next();
       cur_finish;
       cur_finish = cur_finish->get_next())
    {
      cur_insert = cur_finish;
      for (element = head->get_head();
           element != cur_finish;
           element = element->get_next())
        {
          if (*element > *cur_finish)
            {
              cur_insert = element;
              break;
            }
        }
      element = cur_finish;
      if (cur_insert == cur_finish)
        {
          continue;
        }
      if (cur_finish->get_previous())
        {
          if (cur_finish->get_next())
            {
              cur_finish->get_previous()->set_next (cur_finish->get_next());
              cur_finish->get_next()->set_previous (cur_finish->get_previous());
            }
          else
            {
              cur_finish->get_previous()->set_next (NULL);
              head->set_tail (element);
            }
        }
      else
        {
          if (cur_finish->get_next())
            {
              cur_finish->get_next()->set_next (NULL);
              head->set_head (element);
            }
        }

      if (cur_insert == head->get_head())
        {
          head->set_head (element);
        }
      else
        {
          cur_insert->get_previous()->set_next (element);
          element->set_previous (cur_insert->get_previous());
        }
      cur_insert->set_previous (element);
      element->set_next (cur_insert);

    }
  return;
}
