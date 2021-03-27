#ifndef QUEUE_NODE_H
#define QUEUE_NODE_H
#include "tree.h"
#include <cstdio>
#include <string.h>

class queue_node: public tree
{
private:
  queue_node *next;
public:
  queue_node ()
  {
    next = 0;
  }

  ~queue_node ()
  {
    next = 0;
  }

  queue_node *get_next () const
  {
    return next;
  }

  void set_next (queue_node *new_next)
  {
    next = new_next;
  }
};

#endif
