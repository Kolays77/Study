#ifndef STUDENT_NODE_H
#define STUDENT_NODE_H
#include "student.h"
#include <cstdio>
#include <string.h>

class student_node: public student
{
friend class student_list;
private:
  student_node *next, *previous;
public:
  student_node (const char *initial_name = 0,
                int initial_value = 0) :
    student (initial_name, initial_value)
  {
    next = 0;
    previous = 0;
  }
  student_node (const student_node &i) : student (i)
  {
    next = i.next;
    previous = i.previous;
  }

  ~student_node ()
  {
    next = 0;
    previous = 0;
  }

  student_node &operator= (const student_node &i)
  {
    *((student *) this) = i;
    next = i.next;
    previous = i.previous;
    return *this;
  }

  student_node *get_next () const
  {
    return next;
  }

  student_node *get_previous () const
  {
    return previous;
  }

  void set_next (student_node *new_next)
  {
    next = new_next;
  }

  void set_previous (student_node *new_previous)
  {
    previous = new_previous;
  }

  int init (const char *initial_name = 0, int initial_value = 0)
  {
    student::init (initial_name, initial_value);
    next = 0;
    previous = 0;
    return 0;
  }

  void swap (student_node &student2)
  {
    char *buffer_name = student2.name;
    int buffer_value = student2.value;
    student2.name = name;
    student2.value = value;
    name = buffer_name;
    value = buffer_value;
  }
};

#endif
