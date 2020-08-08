#ifndef STUDENT_NODE_H
#define STUDENT_NODE_H
#include "student.h"
#include <cstdio>
#include <string.h>

class student_node: public student
{
friend class student_list;
private:
  student_node *next;
public:
  student_node (const char *initial_name = 0) :
    student (initial_name)
  {
    next = 0;
  }
  student_node (const student_node &i) : student (i)
  {
    next = i.next;
  }

  ~student_node ()
  {
    next = 0;
  }

  student_node &operator= (const student_node &i)
  {
    *((student *) this) = i;
    next = i.next;
    return *this;
  }

  student_node *get_next () const
  {
    return next;
  }

  void set_next (student_node *new_next)
  {
    next = new_next;
  }

  int init (const char *initial_name = 0)
  {
    student::init (initial_name);
    next = 0;
    return 0;
  }
};

#endif
