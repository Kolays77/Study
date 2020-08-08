#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "read.h"
#include "solve.h"
#include "generate.h"

int main (int argc, char **argv)
{
  const char *file_name = "a.txt";
  int result, n = 0, res;
  double counter_of_time;
  student_list *head = 0;

  if (argc != 2 && argc != 1)
    {
      fprintf (stdout, "Usage: %s [<n>]\n", argv[0]);
      return 1;
    }

  head = new student_list;
  if (argc == 1)
    {
      result = read_list (file_name, head);
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
          delete head;
          return -1;
        }
    }
  else
    {
      if ((n = atoi (argv[1])) <= 0)
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
  res = count_local_maximums (head);
  counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
  printf ("The number of local maximums is %d\n", res);

  printf("Elapsed = %.3f\n", counter_of_time);
  delete head;
  return 0;
}
