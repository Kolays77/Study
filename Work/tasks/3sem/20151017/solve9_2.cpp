#include "solve.h"
#include <cstdio>

student_list *delete_sublist (student_list *list, student_list *sub_list, int *len, int *len_sub_list)
{
  student_node *start = 0, *finish, *curr1 = list->get_head(), *curr2 = sub_list->get_head(), *curr_continue = 0;
  int result, need_delete = 0;

  while (curr1)
    {
      if (*curr1 == *curr2)
        {
          if (curr2 == sub_list->get_head() && !(need_delete))
            {
              start = curr1;
              curr_continue = start;
            }
          if (curr2 == sub_list->get_tail())
            {
              finish = curr1;
              need_delete = 1;
              curr_continue = curr_continue->get_next();
              curr1 = curr_continue;
              curr2 = sub_list->get_head();

//              result = delete_segment (list, start, curr1);
//              curr2 = sub_list->get_head();
//              if (result)
//                {
//                  curr1 = list->get_curr();
//                }
//              else
//                {
//                  curr1 = list->get_head();
//                }
//              continue;
            }
          else
            {
              if (curr_continue == finish)
                {
                  result = delete_segment (list, start, finish);
                  curr2 = sub_list->get_head();
                  if (result)
                    {
                      curr1 = list->get_curr();
                    }
                  else
                    {
                      curr1 = list->get_head();
                    }
                  curr1 = curr_continue;
                  need_delete = 0;
                  continue;
                }
              curr_continue = curr_continue->get_next();
              curr1 = curr_continue;
            }
        }
      else
        {
          if (need_delete)
            {
              curr_continue = curr_continue->get_next();
            }
          if (curr2 != sub_list->get_head())
            {
              curr2 = sub_list->get_head();
              continue;
            }
        }
      curr1 = curr1->get_next();
    }
  (*len) -= (*len_sub_list);
  return list;
}

int delete_segment (student_list *list, student_node *start, student_node *curr)
{
  if (start == list->get_head())
    {
      while (list->get_head() != curr)
        {
          list->delete_first();
        }
      if (list->get_head())
        {
          list->delete_first();
        }
      curr = list->get_head();
      return 0;
    }
  else
    {
      list->set_curr (start);
      while (list->get_curr() != curr)
        {
          list->delete_curr();
          list->goto_next();
        }
    }
  if (curr == list->get_tail())
    {
      list->delete_last();
    }
  else
    {
      list->delete_curr();
      list->goto_next();
    }

  curr = list->get_curr();
  return 1;
}
