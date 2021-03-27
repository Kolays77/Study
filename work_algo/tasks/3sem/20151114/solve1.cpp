#include "solve.h"

int count_subtrees_vertex (tree_node *root, int k)
{
  tree_node *left = root->get_left(), *right = root->get_right();
  int count_left = 0, count_right = 0;
  if (root->get_left())
    {
      count_left = count_subtrees_vertex (left, k);
    }
  if (right)
    {
      count_right = count_subtrees_vertex (right, k);
    }
  if (count_elements_in_tree (root) <= k)
    {
      return count_left + count_right + 1;
    }
  return count_left + count_right;
}
