#ifndef STACK_NODE_H
#define STACK_NODE_H
#include "queue.h"
#include <cstdio>
#include <string.h>

class stack_node: public queue
{
private:
  stack_node *prev;
public:
  stack_node ()
  {
    prev = 0;
  }

  ~stack_node ()
  {
    prev = 0;
  }

  stack_node *get_prev () const
  {
    return prev;
  }

  void set_prev (stack_node *new_prev)
  {
    prev = new_prev;
  }
};

#endif
