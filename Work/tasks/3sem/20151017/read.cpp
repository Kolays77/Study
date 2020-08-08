#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "student_list.h"

#define MAX_PRINTABLE_NUMBER 15
#define MAX_LENGTH 25

int read_list (const char *filename, student_list *head)
{
  FILE *file_input;
  char name[MAX_LENGTH];
  int value, idx = 0;
  student_node *curr = 0, *next = 0;

  if (!(file_input = fopen (filename, "r")))
    {
      return -1;
    }

  if (fscanf (file_input, "%s%d", name, &value) == 2)
    {
      curr = new student_node (name, value);
      head->set_head (curr);
      curr->set_previous (NULL);
      idx++;
    }
  else
    {
      return -2;
    }
  while (fscanf (file_input, "%s %d", name, &value) == 2)
    {
      next = new student_node (name, value);
      curr->set_next (next);
      next->set_previous (curr);
      curr = next;
      idx++;
    }
  curr->set_next (NULL);
  head->set_tail (curr);
  if (!feof (file_input))
    {
      fclose (file_input);
      return -2;
    }
  fclose (file_input);
  return idx;
}

void student_list::print_list (int n)
{
  int idx = 0,
      left_board = (n > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : n),
      right_board = ((n - left_board) > left_board ? n - left_board : left_board);

  printf ("LIST OF STUDENTS:\n");
  for (curr = head; curr; curr = curr->get_next())
    {
      if (idx > left_board)
        {
          break;
        }
      printf (" %2d: %s %d\n", idx++, curr->get_name(), curr->get_value());
    }

  if (2 * MAX_PRINTABLE_NUMBER < n)
    {
      printf ("...............\n");
      printf ("...............\n");
    }
  for (; idx < right_board && curr; curr = curr->get_next(), idx++)
    {
      if (idx == right_board)
        {
          break;
        }
    }

  for (; curr; curr = curr->get_next())
    {
      if (idx == n)
        {
          break;
        }
      printf (" %2d: %s %d\n", idx++, curr->get_name(), curr->get_value());
    }
  printf ("\n");
}

void return_error (int result, const char *file_name)
{
  switch (result)
    {
    case (-1):
      fprintf (stdout, "Cannot open %s\n", file_name);
      break;
    case (-2):
      fprintf (stdout, "Cannot read %s\n", file_name);
      break;
    case (-3):
      fprintf (stdout, "%s is empty\n", file_name);
      break;
    default:
      fprintf (stdout, "Unknown error %d in %s\n", result, file_name);
    }
  return;
}
