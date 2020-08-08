#include "solve.h"

int number_of_elements_on_level_h (tree_node *root, int h)
{
  int number_of_elements = 0;
  if (!root)
    {
      return 0;
    }
  if (h == 0)
    {
      return 1;
    }
  for (tree_node *cur_child = root->get_child(); cur_child; cur_child = cur_child->get_next())
    {
      number_of_elements += number_of_elements_on_level_h (cur_child, h - 1);
    }
  return number_of_elements;
}
