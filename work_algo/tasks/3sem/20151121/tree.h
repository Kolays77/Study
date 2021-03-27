#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 1

class b_tree_node
{
private:
  student **students;//[2 * MAX_NUM];
  int num_of_elements;
  b_tree_node **child/*[2 * MAX_NUM + 1]*/, *parent;

public:
  b_tree_node  ()
  {
    num_of_elements = 0;
    students = new student* [2 * MAX_NUM];
    child = new b_tree_node* [2 * MAX_NUM + 1];
  }
  ~b_tree_node () {}

  void attach_student (student *attach);
  int get_num_of_node();
  int create_student (student *initial_student);
  b_tree_node *get_parent () { return parent; }
  void set_parent (b_tree_node *new_parent) { parent = new_parent; }
  b_tree_node *get_child (int i) { return child[i]; }
  student *get_student (int i) { return students[i]; }
  void set_child (int i, b_tree_node *new_child) { child[i] = new_child; }
  void set_student (int i, student *new_student) { students[i] = new_student; }
  int get_num_of_elements () { return num_of_elements; }
  void set_num_of_elements (int n) { num_of_elements = n; }

};

class b_tree: public b_tree_node
{
private:
  b_tree_node *root;
public:
  b_tree  ();
  ~b_tree ();

  b_tree_node *get_root () { return root; }
  void insert_student (student *new_student);
  int read (const char *filename);
  b_tree_node *search_node (student *searching_student);
  void print (b_tree_node *root, int level);
//  void print( int regularity, FILE *fp, b_tree_node *curr_root );
  //void delete_tree( b_tree_node **root );

};

#endif
