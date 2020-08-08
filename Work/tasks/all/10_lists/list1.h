#ifndef LIST_H
#define LIST_H
#include "node1.h"

class list
{
private:
  node *head;
  int number_of_elements;

public:
  list ()
  {
    head = 0;
    number_of_elements = 0;
  }

  node *get_head ()
  {
    return head;
  }

  int get_number_of_elements ()
  {
    return number_of_elements;
  }

  void set_head (node *new_head)
  {
    head = new_head;
  }

  void add_first (node *new_element);
  void add_to_tail (node *new_element);

  int delete_first ();
  int delete_last ();
  int delete_next (node *curr);

  void delete_list();

  int read_list (const char *file_name);
  void print_list (FILE *fp);
  void generate (int number_of_elements);

  ~list ()
  {
    delete_list ();
    head = 0;
    number_of_elements = 0;
  }
};

#endif
