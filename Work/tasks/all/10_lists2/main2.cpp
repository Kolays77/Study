#include <ctime>
#include <cstring>
#include "read2.h"
#include "solve2.h"
#include "generate.h"

int main (int argc, char **argv)
{
  const char *file_name = "a.txt";
  int result, number_of_task, number_of_elements = 0;
  char string[MAX_LENGTH];
  double counter_of_time;
  list *head = 0;

  if (argc != 3 && argc != 2)
    {
      fprintf (stdout, "Usage: %s [#] [<n>]\n", argv[0]);
      return 1;
    }

  if ((number_of_task = atoi (argv[1])) <= 0)
    {
      fprintf (stdout, "Cannot read [#]!\n");
      return 1;
    }
  else
    {
      if (number_of_task > 27)
        {
          fprintf (stdout, "The number of solve is in [1..27]!\n");
          return 1;
        }
    }

  head = new list;
  if (argc == 2)
    {
      result = head->read_list (file_name);
      if (result < 0)
        {
          return_error (result, file_name);
          delete head;
          return -1;
        }
      number_of_elements = result;
    }
  else
    {
      if ((number_of_elements = atoi (argv[2])) <= 0)
        {
          fprintf (stdout, "Cannot read [n]!\n");
          delete head;
          return 1;
        }
      head->generate (number_of_elements);
    }

  head->print_list (stdout);

  counter_of_time = clock();
  switch (number_of_task)
    {
    case (2):
      {
        fprintf (stdout, "Input:  ");
        if (!fgets (string, MAX_LENGTH, stdin))
          {
            fprintf (stdout, "Cannot read!\n");
            delete head;
            return -1;
          }
        string[strlen (string) - 1] = 0;

        head = solve2 (head, string, &compare2);
        break;
      }

    case (4):
      {
        fprintf (stdout, "Input:  ");
        if (!fgets (string, MAX_LENGTH, stdin))
          {
            fprintf (stdout, "Cannot read!\n");
            delete head;
            return -1;
          }
        string[strlen (string) - 1] = 0;

        head = solve2 (head, string, &compare4);
        break;
      }
    case (6):
      {
        fprintf (stdout, "Input:  ");
        if (!fgets (string, MAX_LENGTH, stdin))
          {
            fprintf (stdout, "Cannot read!\n");
            delete head;
            return -1;
          }
        string[strlen (string) - 1] = 0;

        head = solve2 (head, string, &compare6);
        break;
      }

    case (8):
      {
        head = solve8 (head, &compare8);
        break;
      }

    case (10):
      {
        head = solve8 (head, &compare10);
        break;
      }

    case (12):
      {
        head = solve12 (head, &compare12);
        break;
      }

    case (14):
      {
        head = solve12 (head, &compare14);
        break;
      }

    case (16):
      {
        fprintf (stdout, "Input:  ");
        if (!fgets (string, MAX_LENGTH, stdin))
          {
            fprintf (stdout, "Cannot read!\n");
            delete head;
            return -1;
          }
        string[strlen (string) - 1] = 0;
        head = solve16 (head, string, &compare2);
        break;
      }

    case (18):
      {
        fprintf (stdout, "Input:  ");
        if (!fgets (string, MAX_LENGTH, stdin))
          {
            fprintf (stdout, "Cannot read!\n");
            delete head;
            return -1;
          }
        string[strlen (string) - 1] = 0;
        head = solve16 (head, string, &compare4);
        break;
      }

    case (20):
      {
        fprintf (stdout, "Input:  ");
        if (!fgets (string, MAX_LENGTH, stdin))
          {
            fprintf (stdout, "Cannot read!\n");
            delete head;
            return -1;
          }
        string[strlen (string) - 1] = 0;
        head = solve16 (head, string, &compare6);
        break;
      }

    case (22):
      {
        head = solve22 (head, &compare22);
        break;
      }

    case (24):
      {
        head = solve22 (head, &compare24);
        break;
      }

    case (26):
      {
        fprintf (stdout, "Input:  ");
        if (!fgets (string, MAX_LENGTH, stdin))
          {
            fprintf (stdout, "Cannot read!\n");
            delete head;
            return -1;
          }
        string[strlen (string) - 1] = 0;
        head = solve26  (head, string, &compare26);
        break;
      }

    case (27):
      {
        fprintf (stdout, "Input:  ");
        if (!fgets (string, MAX_LENGTH, stdin))
          {
            fprintf (stdout, "Cannot read!\n");
            delete head;
            return -1;
          }
        string[strlen (string) - 1] = 0;
        head = solve26  (head, string, &compare6);
        break;
      }

    default :
      {
        fprintf (stdout, "There is no task with number %d\n", number_of_task);
        delete head;
        return 0;
      }
    }

  counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;

  fprintf (stdout, "\n");
  head->print_list (stdout);
  fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);
  delete head;
  return 0;
}
