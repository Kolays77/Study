#include "sort.h"
#include <cstdio>

void find_sort (student_list *list_of_student)
{
  student_node *element = 0, *cur_max = list_of_student->get_head(), *pointer = 0;

  for (pointer = cur_max->get_next();
       pointer;
       pointer = pointer->get_next())
    {
      if (*pointer > *cur_max)
        {
          cur_max = pointer;
        }
    }
  pointer = list_of_student->get_tail();
  cur_max->swap (*pointer);
  for (pointer = list_of_student->get_tail();
       pointer->get_previous();
       pointer = pointer->get_previous())
    {
      cur_max = list_of_student->get_head();
      for (element = list_of_student->get_head();
           element != pointer;
           element = element->get_next())
        {
          if (*element > *cur_max)
            {
              cur_max = element;
            }
        }
      cur_max->swap (*pointer->get_previous());
    }
  return;
}
