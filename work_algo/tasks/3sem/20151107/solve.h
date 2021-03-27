#ifndef SOLVE_H
#define SOLVE_H

#include "tree.h"

int count_subtrees_vertex (tree_node *root, int k);

int sum_of_number_elements_in_subtrees (tree_node *root, int k);

int count_subtrees_levels (tree_node *root, int k);

int count_subtrees_elements_on_level (tree_node *root, int k);
int maximal_number_of_elements_on_level (tree_node *root);

int number_of_elements_on_level_k (tree_node *root, int k);

#endif // SOLVE_H
