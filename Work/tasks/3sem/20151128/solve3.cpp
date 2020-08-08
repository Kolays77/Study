#include "solve.h"

int count_vertex_levels_K (tree_node *root, int k)
{
  int num_of_vertex_answer = 0;/*,
      num_of_vertex_in_root = 0,
      num_of_levels = 0,
      num_of_vertex_in_cur_child = 0,
      max_level = 0;*/
  if (!root)
    {
      return 0;
    }
  for (tree_node *cur_child = root->get_child(); cur_child; cur_child = cur_child->get_next())
    {
      num_of_vertex_answer += count_vertex_levels_K (cur_child, k);
    }
  if (count_levels (root) <= k)
    {
      //printf ("%s %d - %d\n", root->get_name(), root->get_value(), count_levels (root));
      num_of_vertex_answer += count_elements_in_tree (root);
    }
  return num_of_vertex_answer;
}
