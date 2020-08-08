#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include "student.h"
#include "tree_node.h"

void add_new_node (tree_node *root, tree_node *new_node);
void delete_tree (tree_node *root);
int count_elements_in_tree (tree_node *root);
int count_levels (tree_node *root);

class tree: public tree_node
{
private:
  tree_node *root;
  int m;
public:
  tree (int new_m = 0, tree_node *new_root = 0)
  {
    root = new_root;
    m = new_m;
  }
  tree (const tree &new_tree)
  {
    root = new_tree.root;
    m = new_tree.m;
  }
  ~tree ()
  {
    delete_tree (root);
    delete root;
    root = 0;
    m = 0;
  }

  void set_root (tree_node *new_root)
  {
    root = new_root;
  }

  tree_node *get_root ()
  {
    return root;
  }

  int get_m ()
  {
    return m;
  }

  void set_m (int new_m)
  {
    m = new_m;
  }
};


#endif
