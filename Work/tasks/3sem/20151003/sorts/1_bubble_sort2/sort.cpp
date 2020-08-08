#include "sort.h"
#include <cstdio>

void bubble_sort (student_list *list_of_studets)
{
  student_node *element = 0, *pointer = list_of_studets->get_tail(), *next = 0;
  for (pointer = list_of_studets->get_tail();
       pointer->get_previous();
       pointer = pointer->get_previous())
    {
      for (element = list_of_studets->get_head(), next = element->get_next();
           element != pointer;
           element = next, next = next->get_next())
        {
          if (*next < *element)
            {
              next->swap (*element);
            }
        }
    }
  return;
}

