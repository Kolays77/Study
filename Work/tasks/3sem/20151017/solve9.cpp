#include "solve.h"
#include <cstdio>

student_list *delete_sublist (student_list *list, student_list *sub_list, int *len, int *len_sub_list)
{
  student_node *start = 0, *curr1 = list->get_head(), *curr2 = sub_list->get_head();

  while (curr1)
    {
      if (*curr1 == *curr2)
        {
          if (curr2 == sub_list->get_head())
            {
              start = curr1;
            }
          if (curr2 == sub_list->get_tail())
            {
              delete_segment (list, start, curr1, len, len_sub_list);
              curr2 = sub_list->get_head();
              curr1 = list->get_curr();
              continue;
            }
          else
            {
              curr2 = curr2->get_next();
            }
        }
      else
        {
          if (curr2 != sub_list->get_head())
            {
              curr2 = sub_list->get_head();
              continue;
            }
        }
      curr1 = curr1->get_next();
    }
  return list;
}

void delete_segment (student_list *list, student_node *start, student_node *curr, int *len, int *len_sub_str)
{
  if (start == list->get_head())
    {
      while (list->get_head() != curr)
        {
          list->delete_first();
        }
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
    }//list->print_list(20);
  (*len) -= (*len_sub_str);
  return;
}

//  for (; curr; prev = curr, curr = curr->get_next())
//    {
//      //printf ("%d %d\n", prev->get_value(), curr->get_value());
//      if (*prev == *curr)
//        {
//          if (len_monotonic == 0)
//            {
//              start = prev;
//            }
//          len_monotonic++;
//        }
//      else
//        {
//          if (len_monotonic < k)
//            {
//              len_monotonic = 0;
//              continue;
//            }
//          if (start == head->get_head())
//            {
//              while (head->get_head() != curr)
//                {
//                  head->delete_first();
//                }
//            }
//          else
//            {
//              head->set_curr (start);
//              while (head->get_curr() != curr)
//                {
//                  head->delete_curr();
//                  head->goto_next();
//                }
//            }
//          (*n) -= (len_monotonic + 1);
//          len_monotonic = 0;
//        }
//    }
//  //printf ("%d %d; len %d\n", prev->get_value(), curr->get_value(), len_monotonic);
//  if (len_monotonic > (k - 1))
//    {
//      if (start == head->get_head())
//        {
//          while (head->get_head() != curr)
//            {
//              head->delete_first();
//            }
//        }
//      else
//        {
//          head->set_curr (start);
//          while (head->get_curr() != curr)
//            {
//              head->delete_curr();
//              head->goto_next();
//            }
//        }
//      (*n) -= (len_monotonic + 1);
//      len_monotonic = 0;
//    }
//  return head;
//}
