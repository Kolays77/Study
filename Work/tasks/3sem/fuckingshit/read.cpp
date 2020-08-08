#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "student_list.h"

#define MAX_PRINTABLE_NUMBER 2
#define MAX_LENGTH 200

int student::read (FILE **file_input)
{
  char new_name[MAX_LENGTH];
  int new_value = 0;
  if (fscanf (*file_input, "%s%d", new_name, &new_value) != 2)
    {
      return 0;
    }

  name = new char [strlen (new_name) + 1];
  strcpy (name, new_name);
  value = new_value;

  return 1;
}

int student_list::read (FILE **file_input, int n)
{
  student_node *curr = 0, *next = 0;
  int idx = 0;
  student *curr_student = 0;
  if (curr_student->read (file_input))
    {
      curr = new student_node (curr_student->get_name(), curr_student->get_value());
      head = curr;
      idx++;
    }
  else
    {
      return -2;
    }
  while (curr_student->read (file_input))
    {
      next = new student_node (curr_student->get_name(), curr_student->get_value());
      curr->set_next (next);
      curr = next;
      idx++;
      if (idx == n)
        {
          break;
        }
    }
  curr->set_next (NULL);
  tail = curr;
  if (!(idx == n || feof (*file_input)))
    {
      return -2;
    }
  return idx;
}

void student::print ()
{
  printf ("%s %d\n~~~~~~~~~~~~~~~~\n", name, value);
}

void student_list::print (int n)
{
  int idx = 0,
      left_board = (n > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : n),
      right_board = ((n - left_board) > left_board ? n - left_board : left_board);

  printf ("LIST OF STUDENTS:\n");
  printf ("~~~~~~~~~~~~~~~~\n");
  for (curr = head; curr; curr = curr->get_next())
    {
      if (idx > left_board)
        {
          break;
        }
      printf ("%2d: ", idx++);
      curr->print();
    }

  if (2 * MAX_PRINTABLE_NUMBER < n)
    {
      printf ("...   ...   ...\n...   ...   ...\nd");
    }
  for (; idx < right_board && curr; curr = curr->get_next(), idx++)
    {
      if (idx == right_board)
        {
          break;
        }
    }

  if (n > 2 * MAX_PRINTABLE_NUMBER)
    {
      printf ("~~~~~~~~~~~~~~~~~\n");
    }
  for (; curr; curr = curr->get_next())
    {
      if (idx == n)
        {
          break;
        }
      printf (" %2d: ", idx++);
      curr->print();
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
