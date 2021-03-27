#ifndef READ_H
#define READ_H

#include <cstdio>
#include "tree.h"
int read_tree (const char *filename, tree *root);
void print_tree (tree_node *root, int level, int from);

int generate (tree *root, int n);
void return_error (int result, const char *file_name);

#endif // READ_H