#ifndef LIST_H
#define LIST_H
#include "node.h"

class list
{
private:
  node *head;

public:
  list ()
  {
    head = 0;
  }

  node *get_head ()
  {
    return head;
  }

  void set_head (node *new_head)
  {
    head = new_head;
  }

  void add_first (node *new_element);
  void add_to_tail (node *new_element);

  int delete_first ();
  int delete_last ();

  void delete_list();

  int read_list (const char *file_name);
  void print_list (FILE *fp, int number_of_elements);
  void generate (int number_of_elements);

  ~list ()
  {
    delete_list ();
    head = 0;
  }
};

#endif
