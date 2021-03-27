#include "solve.h"

int count_vertex_subtrees_K (tree_node *root, int k)
{
  int num_of_vertex_in_root = 0, num_of_vertex_answer = 0;
  if (!root)
    {
      return 0;
    }
  for (tree_node *cur_child = root->get_child(); cur_child; cur_child = cur_child->get_next())
    {
      num_of_vertex_in_root += count_elements_in_tree (cur_child);
      num_of_vertex_answer += count_vertex_subtrees_K (cur_child, k);
    }
  if (num_of_vertex_in_root < k)
    {
      num_of_vertex_answer += (num_of_vertex_in_root + 1);
    }
  return num_of_vertex_answer;
}
