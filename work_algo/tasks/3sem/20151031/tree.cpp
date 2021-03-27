#include "tree.h"

void delete_tree (tree_node *root)
{
  if (root->get_left())
    {
      delete_tree (root->get_left());
    }
  if (root->get_right())
    {
      delete_tree (root->get_right());
    }
  delete root;
  root = 0;
  return;
}

void add_new_node (tree_node *root, tree_node *new_node)
{
  int res;
  res = *new_node < *root;
  if (res == 1)
    {
      if (root->get_left())
        {
          add_new_node (root->get_left(), new_node);
        }
      else
        {
          root->set_left (new_node);
        }
    }
  else
    {
      if (root->get_right())
        {
          add_new_node (root->get_right(), new_node);
        }
      else
        {
          root->set_right (new_node);
        }
    }
}
