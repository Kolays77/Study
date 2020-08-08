#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "read.h"
#include "sort.h"
#include "generate.h"

int main (int argc, char **argv)
{
  const char *file_name = "a.txt";
  int result, n = 0;
  double counter_of_time;
  student_list *list_of_studets = 0;

  if (argc != 2 && argc != 1)
    {
      fprintf (stdout, "Usage: %s [<n>]\n", argv[0]);
      return 1;
    }

  list_of_studets = new student_list;
  if (argc == 1)
    {
      result = read_list (file_name, list_of_studets);
      if (result < 0)
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
          delete list_of_studets;
          return -1;
        }
    }
  else
    {
      if ((n = atoi (argv[1])) <= 0)
        {
          fprintf (stdout, "Cannot read [n]!\n");
          delete list_of_studets;
          return 1;
        }
      result = generate (list_of_studets, n);
      if (result < 0)
        {
          fprintf (stdout, "Unknown error %d in generating list", result);
          delete list_of_studets;
          return -2;
        }
    }
  n = result;
  list_of_studets->print_list (n);
  counter_of_time = clock();
  bubble_sort (list_of_studets);
   counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
  list_of_studets->print_list (n);
  fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);
  delete list_of_studets;
  return 0;
}
