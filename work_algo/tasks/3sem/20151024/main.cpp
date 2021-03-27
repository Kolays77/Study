#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include "read.h"
#include "solve.h"
#include "generate.h"

#define MAX_LENGTH 100
int main (int argc, char **argv)
{
  const char *file_name = "a.txt";
  int result, index, n = 0;
  char name[MAX_LENGTH]; int value = 0;
  double counter_of_time;
  student_list *head = 0;
  student *element;

  if (argc != 3 && argc != 2)
    {
      fprintf (stdout, "Usage: %s [#] [<n>]\n", argv[0]);
      return 1;
    }

  if ((index = atoi (argv[1])) <= 0)
    {
      fprintf (stdout, "Cannot read [#]!\n");
      return 1;
    }
  else
    {
      if (index > 9)
        {
          fprintf (stdout, "The number of solve is in [1..9]!\n");
          return 1;
        }
    }

  head = new student_list;
  if (argc == 2)
    {
      result = read_list (file_name, head);
      if (result < 0)
        {
          return_error (result, file_name);
          delete head;
          return -1;
        }
    }
  else
    {
      if ((n = atoi (argv[2])) <= 0)
        {
          fprintf (stdout, "Cannot read [n]!\n");
          delete head;
          return 1;
        }
      result = generate (head, n);
      if (result < 0)
        {
          fprintf (stdout, "Unknown error %d in generating list", result);
          delete head;
          return -2;
        }
    }
  n = result;
  head->print_list (n);
  counter_of_time = clock();
  switch (index)
    {
    case (1):
      fprintf (stdout, "Input student:\n");
      if (!fgets (name, MAX_LENGTH, stdin))
        {
          fprintf (stdout, "Cannot read name!\n");
          delete head;
          return -1;
        }
      name[strlen (name) - 1] = 0;
      fprintf (stdout, "Input value:\n");
      if (fscanf (stdin, "%d", &value) != 1)
        {
          fprintf (stdout, "Cannot read value!\n");
          delete head;
          return -1;
        }
      element = new student (name, value);
      head = make_new_list1 (head, element, &n);
      delete element;
      break;

    case (2):
      head = delete_less2 (head, &n);
      break;

    case (3):
      head = delete_equal3 (head, &n);
      break;

    case (4):
      fprintf (stdout, "Input student:\n");
      if (!fgets (name, MAX_LENGTH, stdin))
        {
          fprintf (stdout, "Cannot read name!\n");
          delete head;
          return -1;
        }
      name[strlen (name) - 1] = 0;
      fprintf (stdout, "Input value:\n");
      if (fscanf (stdin, "%d", &value) != 1)
        {
          fprintf (stdout, "Cannot read value!\n");
          delete head;
          return -1;
        }
      element = new student (name, value);
      head = delete_more4 (head, element, &n);
      delete element;
      break;

    case (5):
      head = delete_increasing5 (head, &n);
      break;

    case (6):
      fprintf (stdout, "Input student:\n");
      if (!fgets (name, MAX_LENGTH, stdin))
        {
          fprintf (stdout, "Cannot read name!\n");
          delete head;
          return -1;
        }
      name[strlen (name) - 1] = 0;
      fprintf (stdout, "Input value:\n");
      if (fscanf (stdin, "%d", &value) != 1)
        {
          fprintf (stdout, "Cannot read value!\n");
          delete head;
          return -1;
        }
      element = new student (name, value);
      head = delete_6 (head, element, &n);
      delete element;
      break;
    }

  counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
  head->print_list (n);
  fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);
  delete head;
  head->print_list(10);
  return 0;
}
