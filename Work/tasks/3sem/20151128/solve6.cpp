#include "solve.h"

int count_elements_branches_K (tree_node *root, int k, int len)
{
  int number_of_elements = 0;
  if (!root)
    {
      return 0;
    }
  if (!root->get_child() && len == k)
    {
      return k;
    }
  for (tree_node *cur_child = root->get_child(); cur_child; cur_child = cur_child->get_next())
    {
      number_of_elements += count_elements_branches_K (cur_child, k, len + 1);
    }
  return number_of_elements;
}
