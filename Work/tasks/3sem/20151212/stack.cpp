#include "stack.h"

void stack::pop ()
{
  stack_node *curr_last = last->get_prev();
  delete last;
  last = curr_last;
  number_of_elements--;
}

stack_node *stack::get_last()
{
  return last;
}

int stack::empty ()
{
  if (last)
    {
      return 0;
    }
  return 1;
}

void stack::add (stack_node *new_element) //+
{
  new_element->set_prev (last);
  last = new_element;
  number_of_elements++;
}
