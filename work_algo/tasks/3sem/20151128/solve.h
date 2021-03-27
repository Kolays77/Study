#ifndef SOLVE_H
#define SOLVE_H

#include "tree.h"

int count_vertex_children_K (tree_node *root, int k);

int count_vertex_subtrees_K (tree_node *root, int k);

int count_vertex_levels_K (tree_node *root, int k);

int count_vertex_subtrees_on_level_K (tree_node *root, int k);
int maximal_number_of_elements_on_level (tree_node *root);

int number_of_elements_on_level_h (tree_node *root, int k);

int count_elements_branches_K (tree_node *root, int k, int len);

#endif // SOLVE_H
