#include "solve.h"

int count_elements_in_subtree (tree_node *root)
{
  int left = 0, right = 0;
  if (root->get_left())
    {
      left = count_elements_in_subtree (root->get_left());
    }
  if (root->get_right())
    {
      right = count_elements_in_subtree (root->get_right());
    }
  return left + right + 1;
}
