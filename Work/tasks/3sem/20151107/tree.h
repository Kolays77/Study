#ifndef TREE_H
#define TREE_H

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
public:
  tree (tree_node *new_root = 0)
  {
    root = new_root;
  }
  tree (const tree &new_tree)
  {
    root = new_tree.root;
  }
  ~tree ()
  {
    delete_tree (root);
    root = 0;
  }

  tree_node *get_root()
  {
    return root;
  }

  void set_root (tree_node *new_root)
  {
    root = new_root;
  }
};


#endif
