#include "solve.h"

static int counter = 0;

int count_having_one_descedant (tree_node *root)
{
  tree_node *left = root->get_left(), *right = root->get_right();
  if ((left && !right) || (right && !left))
    {
      counter++;
    }
  if (left)
    {
      count_having_one_descedant (root->get_left());
    }
  if (right)
    {
      count_having_one_descedant (root->get_right());
    }
  return counter;
}

