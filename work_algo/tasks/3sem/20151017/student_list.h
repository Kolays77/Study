#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H
#include "student_node.h"

class student_list: public student_node
{
private:
  student_node *head;
  student_node *tail;
  student_node *curr;
public:
  student_list ()
  {
    head = 0;
    tail = 0;
    curr = 0;
  }
  void add_next (student_node *new_element);
  void add_previous (student_node *new_element);
  void add_first (student_node *new_element);
  void add_last (student_node *new_element);
  void delete_next ();
  void delete_curr ();
  void delete_previous ();
  void delete_first ();
  void delete_last ();
  void goto_head ();
  void goto_tail ();
  void goto_next ();
  void goto_previous ();

  ~student_list ()
  {
    student_node *next, *cur;
    for (cur = head; cur; cur = next)
      {
        next = cur->get_next();
        delete cur;
      }
    head = 0;
    curr = 0;
  }

  student_node *get_head ()
  {
    return head;
  }
  student_node *get_tail ()
  {
    return tail;
  }
  student_node *get_curr ()
  {
    return curr;
  }

  void set_head (student_node *new_head)
  {
    head = new_head;
  }
  void set_tail (student_node *new_tail)
  {
    tail = new_tail;
  }
  void set_curr (student_node *new_curr)
  {
    curr = new_curr;
  }

  void print_list (int n);
};

#endif
