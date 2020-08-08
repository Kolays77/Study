#include "generate.h"

void generate_string (char *string)
{
  char ch;
  int length = rand () % (MAX_LEN - MIN_LEN + 1) + MIN_LEN;
  for (int idx = 0; idx < length; idx++)
    {
      ch = rand () % (Z - A + 1) + A;
      string[idx] = ch;
    }
  string[length] = 0;
}

void list::generate (int number)
{
  char current_name[MAX_LEN];
  node *curr = 0, *next = 0;

  srand (time (NULL));

  generate_string (current_name);
  curr = new node (current_name);
  set_head (curr);
  number_of_elements = number;
  for (int idx = 1; idx < number; idx++)
    {
      generate_string (current_name);
      next = new node (current_name);
      curr->set_next (next);
      curr = next;
    }
  curr->set_next (NULL);
  return;
}
