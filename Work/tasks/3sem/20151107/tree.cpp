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

int count_elements_in_tree (tree_node *root)
{
  int left = 0, right = 0;
  if (root->get_left())
    {
      left = count_elements_in_tree (root->get_left());
    }
  if (root->get_right())
    {
      right = count_elements_in_tree (root->get_right());
    }
  return left + right + 1;
}

int count_levels (tree_node *root)
{
  tree_node *left = root->get_left(), *right = root->get_right();
  int left_levels = 0, right_levels = 0;
  if (left)
    {
      left_levels = count_levels (left);
    }
  if (right)
    {
      right_levels = count_levels (right);
    }
  if (left_levels > right_levels)
    {
      return left_levels + 1;
    }
  return right_levels + 1;
}
