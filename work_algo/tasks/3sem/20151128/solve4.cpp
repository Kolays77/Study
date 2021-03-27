#include "solve.h"

int count_vertex_subtrees_on_level_K (tree_node *root, int k)
{
  tree_node *cur_child;
  int number_of_elements = 0, in_cur_tree = 0;
  if (!root)
    {
      return 0;
    }
  cur_child = root->get_child();
  if (!cur_child)
    {
      return 1;
    }
  in_cur_tree = maximal_number_of_elements_on_level (root);
  if (in_cur_tree <= k)
    {
      number_of_elements += count_elements_in_tree (root);
    }
  //printf ("%s - %d %d\n", root->get_name(), in_cur_tree, count_elements_in_tree (root));
  for (; cur_child; cur_child = cur_child->get_next())
    {
      number_of_elements += count_vertex_subtrees_on_level_K (cur_child, k);
    }
  return number_of_elements;
}

int maximal_number_of_elements_on_level (tree_node *root)
{
  int max_number = 1, curr_number = 1, max_level = count_levels (root);
  for (int level = 0; level < max_level; level++)
    {
      curr_number = number_of_elements_on_level_h (root, level);
      if (max_number < curr_number)
        {
          max_number = curr_number;
        }
    }
  return max_number;
}

