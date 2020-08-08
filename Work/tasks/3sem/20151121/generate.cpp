#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "student.h"
#include "tree.h"

#define MAX_LENGTH 4
#define MIN_LENGTH 4
#define MAX_VALUE 10

//int generate (b_tree *root, int n)
//{
//  int idx, idx_string, current_length, current_value = 0;
//  char current_char, current_name[MAX_LENGTH + 1];
//  tree_node *new_root = 0, *new_node = 0;

//  srand (time (NULL));

//  for (idx = 0; idx < n; idx++)
//    {
//      current_length = rand () % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH;
//      for (idx_string = 0; idx_string < current_length; idx_string++)
//        {
//          current_char = rand () % ('z' - 'a' + 1) + 'a';
//          current_name[idx_string] = current_char;
//        }
//      current_name[idx_string] = 0;
//      current_value = rand () % (MAX_VALUE + 1);
//      if (idx == 0)
//        {
//          new_root = new tree_node;
//          new_root->init (current_name, current_value);
//          root->set_root (new_root);
//          continue;
//        }
//      new_node = new tree_node;
//      new_node->init (current_name, current_value);
//      add_new_node (new_root, new_node);
//    }

//  return n;
//}
