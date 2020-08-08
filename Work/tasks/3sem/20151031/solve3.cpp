#include "solve.h"

int maximal_number_of_elements_on_level (tree_node *root)
{
  int max_number = 1, curr_number = 1, level, max_level = length_of_maximal_branch (root);
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

int number_of_elements_on_level_k (tree_node *root, int k)
{
  int number_on_left = 0, number_on_right = 0;
  if (k == 0)
    {
      return 1;
    }
  if (root->get_left())
    {
      number_on_left = number_of_elements_on_level_k (root->get_left(), k - 1);
    }
  if (root->get_right())
    {
      number_on_right = number_of_elements_on_level_k (root->get_right(), k - 1);
    }
  return number_on_left + number_on_right;
}
