#ifndef QUEUE_H
#define QUEUE_H

#include "student_list.h"

class queue : public student_node
{
private:
  student_node *top;
  student_node *tail;
public:
  queue ()
  {
    top = 0;
    tail = 0;
  }

  ~queue ();
  void pop_left ();
  student_node *get_top ();
  void add (student_node *new_student);
  void add (const char *initial_name, int initial_value);
  int empty ();
  int generate (int n);
  int read (FILE **fp, int n);
  void print (int n);
};

#endif // QUEUE_H
