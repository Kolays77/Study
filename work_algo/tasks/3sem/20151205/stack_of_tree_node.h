#ifndef stack_of_tree_node_H
#define stack_of_tree_node_H

#include "tree_node.h"

class stack_of_tree_node
{
private:
  tree_node *last;
public:
  stack_of_tree_node ()
  {
    last = 0;
  }
  ~stack_of_tree_node ()
  {
    while (last)
      {
        pop ();
      }
  }

  void add (tree_node *new_element)
  {
    new_element->set_prev (last);
    last = new_element;
  }

  void clean ()
  {
    last = 0;
  }

  void pop ()
  {
    tree_node *curr_last = last->get_prev();
    last = curr_last;
  }

  int empty ()
  {
    if (last)
      {
        return 0;
      }
    return 1;
  }

  tree_node *get_last ()
  {
    return last;
  }
};

#endif // stack_of_tree_node_H
