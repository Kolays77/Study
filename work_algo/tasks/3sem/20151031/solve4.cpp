#include "solve.h"
#include <cstdio>
#include <cmath>

static int max_difference = 0;

int maximal_difference (tree_node *root)
{
  tree_node *left = root->get_left(), *right = root->get_right();
  int len_left = 0, len_right = 0;

  len_left = 0; len_right = 0;
  if (left)
    {
      len_left = length_of_maximal_branch (left);
      maximal_difference (left);
    }
  if (right)
    {
      len_right = length_of_maximal_branch (right);
      maximal_difference (right);
    }
  if (len_left != 0 && len_right != 0)
    {
      if (fabs (len_left - len_right) > max_difference)
        {
          max_difference = fabs (len_left - len_right);
        }
    }

  return max_difference;
}
