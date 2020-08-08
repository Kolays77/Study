#include "tree.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int comparator (tree_node *first, tree_node *second)
{
  //return (first->get_value() - second->get_value()) % 3 - 1;
  return (first->get_value() & 1) - (second->get_value() & 1);
}

void delete_tree (tree_node *root)
{
  if (!root)
    {
      return;
    }
  tree_node *curr_child = root->get_child(), *next_child;
  while (curr_child)
    {
      next_child = curr_child->get_next();
      if (!next_child)
        {
          delete_tree (curr_child);
          break;
        }
      root->set_child (next_child);
      delete_tree (curr_child);
      curr_child = next_child;
    }
  delete root;
  next_child = 0;
  root = 0;
  return;
}

void add_new_node (tree_node *root, tree_node *new_node)
{
  int res = comparator (new_node, root);
  tree_node *cur_child = root->get_child (), *prev_child = 0;
  new_node->set_idx_of_child (res);
  if (!cur_child)
    {
      root->set_child (new_node);
      return;
    }
  for (; cur_child && cur_child->get_idx_of_child () <= res; prev_child = cur_child, cur_child = cur_child->get_next())
    {}
  if (!prev_child)
    {
      root->set_child (new_node);
      new_node->set_next (cur_child);
      return;
    }
  if (res == prev_child->get_idx_of_child())
    {
      add_new_node (prev_child, new_node);
    }
  else
    {
      prev_child->set_next (new_node);
      new_node->set_next (cur_child);
    }
  return;
}

int count_elements_in_tree (tree_node *root)
{
  int number_vertex = 1;
  if (!root)
    {
      return 0;
    }
  for (tree_node *cur_child = root->get_child(); cur_child; cur_child = cur_child->get_next())
    {
      number_vertex += count_elements_in_tree (cur_child);
    }
  return number_vertex;
}

int count_levels (tree_node *root)
{
  int max_level = 0, cur_level = 0;
  if (!root)
    {
      return 0;
    }
  if (!root->get_child())
    {
      return 1;
    }
  for (tree_node *cur_child = root->get_child(); cur_child; cur_child = cur_child->get_next())
    {
      cur_level = count_levels (cur_child);
      if (cur_level > max_level)
        {
          max_level = cur_level;
        }
    }
  return max_level + 1;
}
