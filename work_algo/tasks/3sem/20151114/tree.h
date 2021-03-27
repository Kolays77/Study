#ifndef TREE_H
#define TREE_H

#include "student.h"
#include "tree_node.h"

void add_new_node (tree_node *root, student *new_node);
void insert_new_student (student new_student, tree_node *curr_node);
//void delete_tree (tree_node *root);
#endif
