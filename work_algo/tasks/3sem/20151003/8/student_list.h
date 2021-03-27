#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H
#include "student_node.h"

class student_list: public student_node
{
private:
  student_node *head;
  student_node *curr;
public:
  student_list ()
  {
    head = 0;
    curr = 0;
  }
  void add (student_node *new_element);
  void add_first (student_node *new_element);
  void delete_next ();
  void delete_first ();
  void goto_head ();
  void goto_next ();
  ~student_list ()
  {
    while (head)
      delete_first ();
    head = 0;
    curr = 0;
  }
  student_node *get_head ()
  {
    return head;
  }
  void set_head (student_node *new_head)
  {
    head = new_head;
  }
  void print_list (int n);
};

#endif
