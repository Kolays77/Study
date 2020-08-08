#ifndef QUEUE_H
#define QUEUE_H

#include "queue_node.h"

class queue
{
private:
  queue_node *top;
  queue_node *tail;
  int number_of_elements;
public:
  queue ()
  {
    top = 0;
    tail = 0;
    number_of_elements = 0;
  }
  ~queue ()
  {
    while (top)
      {
        pop_left();
      }
    top = 0;
    number_of_elements = 0;
  }

  void pop_left ();
  queue_node *get_top ();
  void add (queue_node *new_);
  int empty ();

  int read (FILE *fp, int n2, int n3);
  void print (const char *pretty_string);

  void menu ();//stack *global_structure);
};

#endif // QUEUE_H
