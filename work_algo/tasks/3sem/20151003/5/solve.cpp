
#include <stdio.h>
#include "solve.h"

int type_of_list (student_list *head)
{
  bool decreasing = 1,
       increasing = 1,
       constant = 1;
  student_node *previous = head->get_head(), *element;

  for (element = previous->get_next(); element; previous = element,
                                                element = element->get_next())
    {
      //printf ("%d %d\n", previous->get_value(), element->get_value());
      //printf ("< - %d; > - %d; == -%d;\n", previous < element, previous > element, !(previous < element) && !(previous > element));
      if (*previous < *element)
        {
          decreasing = constant = 0;
        }
      if (*previous > *element)
        {
          increasing = constant = 0;
        }
    }
  if (constant && decreasing && constant)
    {
      return 4;
    }
  if (constant)
    {
      return 3;
    }
  if (decreasing)
    {
      return 2;
    }
  if (increasing)
    {
      return 1;
    }
  return 0;
}
