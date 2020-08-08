#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "student.h"
#include "student_list.h"
#include "student_node.h"

#define MAX_LENGTH 25
#define MIN_LENGTH 5
#define MAX_VALUE 1000

int generate (student_list *head, int n)
{
  int idx, idx_string, current_length, current_value = 0;
  char current_char, current_name[MAX_LENGTH];
  student_node *curr = 0, *next = 0;

  srand (time (NULL));

  for (idx = 0; idx < n; idx++)
    {
      current_length = rand () % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH;
      for (idx_string = 0; idx_string < current_length; idx_string++)
        {
          current_char = rand () % ('z' - 'a' + 1) + 'a';
          current_name[idx_string] = current_char;
        }
      current_name[idx_string] = 0;
      current_value = rand () % (MAX_VALUE + 1);
      if (idx == 0)
        {
          curr = new student_node (current_name, current_value);
          head->set_head (curr);
          continue;
        }
      next = new student_node (current_name, current_value);
      curr->set_next (next);
      curr = next;
    }

  curr->set_next (NULL);

  return n;
}
