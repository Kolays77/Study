#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include "read.h"
#include "generate.h"
#include "queue.h"

#define MAX_LENGTH 100
int main (int argc, char **argv)
{
  char file_name[MAX_LENGTH];
  int result;
  stack *new_stack;
  int n1 = 0, n2 = 0, n3 = 0;

  FILE *fp = 0;
  if (argc != 4 && argc != 5)
    {
      fprintf (stdout, "Usage: %s [n1] [n2] [n3] [file = 0]\n", argv[0]);
      return 1;
    }

  if ((n1 = atoi (argv[1])) <= 0)
    {
      fprintf (stdout, "Cannot read [n1]!\n");
      return 1;
    }
  if ((n2 = atoi (argv[2])) <= 0)
    {
      fprintf (stdout, "Cannot read [n2]!\n");
      return 1;
    }
  if ((n3 = atoi (argv[3])) <= 0)
    {
      fprintf (stdout, "Cannot read [n3]!\n");
      return 1;
    }

  new_stack = new stack ();
  if (argc == 5 && strcmp (argv[4], "0"))
    {
      strcpy (file_name, argv[4]);
      if (!(fp = fopen (file_name, "r")))
        {
          fprintf (stdout, "Cannot open file\n");
          return -1;
        }
    }
  else
    {
      if (generate_file ("a.txt", n1 * n2 * n3) != 0)
        {
          fprintf (stdout, "Cannot create %s!\n", file_name);
          return -1;
        }
      if (!(fp = fopen ("a.txt", "r")))
        {
          fprintf (stdout, "Cannot open file\n");
          return -1;
        }
    }

  result = new_stack->read (fp, n1, n2, n3);
  if (result < 0)
    {
      return_error (result, file_name);
      delete new_stack;
      fclose (fp);
      return -1;
    }
  fclose (fp);
  new_stack->print();

  new_stack->menu();
  delete new_stack;
  return 0;
}
