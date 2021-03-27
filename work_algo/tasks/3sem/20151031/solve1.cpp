#include "solve.h"

static int leaves = 0;

int count_leaves (tree_node *root)
{
  tree_node *left = root->get_left(), *right = root->get_right();
  if (!left && !right)
    {
      leaves++;
      return leaves;
    }
  if (left)
    {
      count_leaves (root->get_left());
    }
  if (right)
    {
      count_leaves (root->get_right());
    }
  return leaves;
}
