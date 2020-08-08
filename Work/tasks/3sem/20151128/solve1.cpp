#include "solve.h"

int count_vertex_children_K (tree_node *root, int k)
{
  int num_of_children = 0, num_of_vertexes = 0;
  if (!root)
    {
      return 0;
    }
  for (tree_node *cur_child = root->get_child(); cur_child; cur_child = cur_child->get_next())
    {
      num_of_vertexes += count_vertex_children_K (cur_child, k);
      num_of_children++;
    }
  if (num_of_children == k)
    {
      num_of_vertexes++;
    }
  return num_of_vertexes;
}
