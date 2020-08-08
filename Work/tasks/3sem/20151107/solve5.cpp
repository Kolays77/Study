#include "solve.h"

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

