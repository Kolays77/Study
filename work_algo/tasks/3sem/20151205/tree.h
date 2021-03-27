#ifndef TREE_H
#define TREE_H

#include "tree_node.h"

void delete_tree (tree_node *root);

class tree
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
  void add (tree_node *current_root, tree_node *new_node);
  int read (FILE *fp, int n3);
  void print (tree_node *root, int level, const char *pretty_string);

  void menu ();
};


#endif
