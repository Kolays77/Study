#ifndef STACK_H
#define STACK_H
#include "stack_node.h"

class stack
{
private:
  stack_node *last;
  int number_of_elements;
public:
  stack ()
  {
    last = 0;
    number_of_elements = 0;
  }
  ~stack ()
  {
    while (last)
      {
        pop ();
      }
    last = 0;
    number_of_elements = 0;
  }

  void add (stack_node *new_element);
  void pop ();
  int empty ();
  stack_node *get_last ();

  int read (FILE *fp, int n1, int n2, int n3);
  void print ();

  void menu ();
};

#endif
