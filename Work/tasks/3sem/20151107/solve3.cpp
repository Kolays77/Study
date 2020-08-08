#include "solve.h"

int count_subtrees_levels (tree_node *root, int k)
{
  tree_node *left = root->get_left(), *right = root->get_right();
  int count_left = 0, count_right = 0, num_of_levels = 0;
  if (left)
    {
      count_left = count_subtrees_levels (left, k);
    }
  if (right)
    {
      count_right = count_subtrees_levels (right, k);
    }
  num_of_levels = count_levels (root);
  if (num_of_levels <= k)
    {
      return count_left + count_right + 1;
    }
  return count_left + count_right;
}
