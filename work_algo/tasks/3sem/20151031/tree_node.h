#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "student.h"

class tree_node: public student
{
private:
  tree_node *left;
  tree_node *right;

public:
  tree_node ()
  {
    left = 0;
    right = 0;
  }

  ~tree_node ()
  {
    left = 0;
    right = 0;
  }

  tree_node *get_left()
  {
    return left;
  }

  tree_node *get_right()
  {
    return right;
  }

  void set_left (tree_node *new_left)
  {
    left = new_left;
  }

  void set_right (tree_node *new_right)
  {
    right = new_right;
  }

};

#endif // TREE_NODE_H
