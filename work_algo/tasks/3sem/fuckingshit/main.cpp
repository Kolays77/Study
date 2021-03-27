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
  int result, n = 0;
  queue *queue_student = 0;
  FILE *fp = 0;
  if (argc != 3)
    {
      fprintf (stdout, "Usage: %s [n] [file = 0]\n", argv[0]);
      return 1;
    }

  if ((n = atoi (argv[1])) <= 0)
    {
      fprintf (stdout, "Cannot read [n]!\n");
      return 1;
    }

  queue_student = new queue;
  if (strcmp (argv[2], "0"))
    {
      strcpy(file_name, argv[2]);

      if (!(fp = fopen (file_name, "r")))
        {
          return_error (-1, file_name);
          delete queue_student;
          return -1;
        }
      result = queue_student->read (&fp, n);
      if (result < 0)
        {
          return_error (result, file_name);
          delete queue_student;
          fclose (fp);
          return -1;
        }
      fclose (fp);

    }
  else
    {
      result = queue_student->generate (n);
      if (result < 0)
        {
          fprintf (stdout, "Unknown error %d in generating list", result);
          delete queue_student;
          return -2;
        }
    }
  n = result;
  //queue_student->print (n);

//  printf ("%s\n", queue_student->get_top()->get_name());
//  printf ("%s\n", queue_student->get_top()->get_next()->get_name());
//  printf ("%s\n", queue_student->get_top()->get_next()->get_next()->get_name());

//  char name[200]; int value;
//  student_node *la;
//  if (scanf ("%s %d", name, &value) != 2)
//    {
//      return 0;
//    }
//  else
//    {
//      la = new student_node (name, value);
//    }
//  printf ("\n");
//  queue_student->add (la);
//  if (!queue_student->empty())
//    {
//      queue_student->pop_left();
//    }

  queue_student->print(n);

  delete queue_student;
  return 0;
}
