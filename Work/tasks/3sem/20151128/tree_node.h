#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "student.h"

class tree_node: public student
{
private:
  tree_node *child;
  tree_node *next;
  tree_node *first;
  int idx_of_child;

public:
  tree_node ()
  {
    child = 0;
    next = 0;
    first = 0;
    idx_of_child = 0;
  }

  ~tree_node ()
  {
    child = 0;
    next = 0;
    first = 0;
    idx_of_child = 0;
  }

  tree_node *get_first()
  {
    return first;
  }

  tree_node *get_next()
  {
    return next;
  }

  tree_node *get_child ()
  {
    return child;
  }

  int get_idx_of_child ()
  {
    return idx_of_child;
  }

  void set_first (tree_node *new_first)
  {
    first = new_first;
  }

  void set_next (tree_node *new_next)
  {
    next = new_next;
  }

  void set_child (tree_node *new_child)
  {
    child = new_child;
  }

  void set_idx_of_child (int idx)
  {
    idx_of_child = idx;
  }
};

#endif // TREE_NODE_H
