#include "solve.h"

int sum_of_number_elements_in_subtrees (tree_node *root, int k)
{
  tree_node *left = root->get_left(), *right = root->get_right();
  int count_left = 0, count_right = 0, num_elements = 0;
  if (left)
    {
      count_left = sum_of_number_elements_in_subtrees (left, k);
    }
  if (right)
    {
      count_right = sum_of_number_elements_in_subtrees (right, k);
    }
  num_elements = count_elements_in_tree (root);
  if (num_elements <= k)
    {
      return count_left + count_right + num_elements;
    }
  return count_left + count_right;
}
