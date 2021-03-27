#include "generate.h"

void generate_string (char *string)
{
  char ch;
  int length = rand () % (MAX_LEN - MIN_LEN + 1) + MIN_LEN;
  for (int idx = 0; idx < length; idx++)
    {
      ch = rand () % ('z' - 'a' + 1) + 'a';
      string[idx] = ch;
    }
  string[length] = 0;
}

void list::generate (int number_of_elements)
{
  char current_name[MAX_LEN];
  node *curr = 0, *next = 0;

  srand (time (NULL));

  generate_string (current_name);
  curr = new node (current_name);
  set_head (curr);

  for (int idx = 1; idx < number_of_elements; idx++)
    {
      generate_string (current_name);
      next = new node (current_name);
      curr->set_next (next);
      curr = next;
    }
  curr->set_next (NULL);
  return;
}
