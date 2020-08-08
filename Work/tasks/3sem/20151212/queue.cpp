#include "queue.h"

#define MAX_PRINTABLE_NUMBER 3

int queue::empty ()
{
  if (top)
    {
      return 0;
    }
  return 1;
}

void queue::pop_left ()
{
  queue_node *new_top = top->get_next();
  delete top;
  top = new_top;
  number_of_elements--;
}

queue_node *queue::get_top()
{
  return top;
}

void queue::add (queue_node *new_)
{
  if (!top)
    {
      top = new_;
      tail = new_;
    }
  else
    {
      tail->set_next (new_);
      tail = new_;
    }
  number_of_elements++;
}
