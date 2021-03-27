#include "solve.h"

static int length = 0, max_length = 0;

int length_of_maximal_branch (tree_node *root, int start)
{
  tree_node *left = root->get_left(), *right = root->get_right();
  if (!start)
    {
      length = 0;
      max_length = 0;
    }
  length++;
  if (!left && !right)
    {
      if (max_length < length)
        {
          max_length = length;
        }
      length--;
      return max_length;
    }
  if (left)
    {
      length_of_maximal_branch (root->get_left(), 1);
    }
  if (right)
    {
      length_of_maximal_branch (root->get_right(), 1);
    }
  length--;
  return max_length;
}
