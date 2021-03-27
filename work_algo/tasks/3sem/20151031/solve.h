#ifndef SOLVE_H
#define SOLVE_H

#include "tree.h"

int count_leaves (tree_node *root);

int length_of_maximal_branch (tree_node *root, int start = 0);

int maximal_number_of_elements_on_level (tree_node *root);
int number_of_elements_on_level_k (tree_node *root, int k);

int maximal_difference (tree_node *root);

int count_having_one_descedant (tree_node *root);

#endif // SOLVE_H
