#include "solve.h"

int count_subtrees_elements_on_level (tree_node *root, int k)
{
  tree_node *left = root->get_left(), *right = root->get_right();
  int count_left = 0, count_right = 0, in_cur_tree = 0;

  if (!left && !right)
    {
      return 1;
    }
  in_cur_tree = maximal_number_of_elements_on_level (root);
  if (in_cur_tree <= k)
    {
      return count_elements_in_tree (root);
    }
  if (left)
    {
      count_left = count_subtrees_elements_on_level (left, k);
    }
  if (right)
    {
      count_right = count_subtrees_elements_on_level (right, k);
    }
  return count_left + count_right;
}

int maximal_number_of_elements_on_level (tree_node *root)
{
  int max_number = 1, curr_number = 1, level, max_level = count_levels (root);
  for (level = 0; level < max_level; level++)
    {
      curr_number = number_of_elements_on_level_k (root, level);
      if (max_number < curr_number)
        {
          max_number = curr_number;
        }
    }
  return max_number;
}
