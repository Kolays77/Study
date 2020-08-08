#include <ctime>
#include <cstring>
#include "read.h"
#include "solve.h"
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

  head->print_list (stdout, number_of_elements);

  counter_of_time = clock();
  switch (number_of_task)
    {
    case (1):
      {
        fprintf (stdout, "Input:  ");
        if (!fgets (string, MAX_LENGTH, stdin))
          {
            fprintf (stdout, "Cannot read!\n");
            delete head;
            return -1;
          }
        string[strlen (string) - 1] = 0;

        head = solve1 (head, string, &number_of_elements);
        break;
      }
    case (3):
      {
        fprintf (stdout, "Input:  ");
        if (!fgets (string, MAX_LENGTH, stdin))
          {
            fprintf (stdout, "Cannot read!\n");
            delete head;
            return -1;
          }
        string[strlen (string) - 1] = 0;

        head = solve3 (head, string, &number_of_elements);
        break;
      }
    case (5):
      {
        fprintf (stdout, "Input:  ");
        if (!fgets (string, MAX_LENGTH, stdin))
          {
            fprintf (stdout, "Cannot read!\n");
            delete head;
            return -1;
          }
        string[strlen (string) - 1] = 0;

        head = solve5 (head, string, &number_of_elements);
        break;
      }
    case (7):
      {
        head = solve7 (head, &number_of_elements);
        break;
      }
    case (9):
      {
        head = solve9 (head, &number_of_elements);
        break;
      }
    case (11):
      {
        head = solve11 (head, &number_of_elements);
        break;
      }
    case (13):
      {
        head = solve13 (head, &number_of_elements);
        break;
      }
    case (15):
      {
        fprintf (stdout, "Input:  ");
        if (!fgets (string, MAX_LENGTH, stdin))
          {
            fprintf (stdout, "Cannot read!\n");
            delete head;
            return -1;
          }
        string[strlen (string) - 1] = 0;

        head = solve15 (head, string, &number_of_elements);
        break;
      }
    case (17):
      {
        fprintf (stdout, "Input:  ");
        if (!fgets (string, MAX_LENGTH, stdin))
          {
            fprintf (stdout, "Cannot read!\n");
            delete head;
            return -1;
          }
        string[strlen (string) - 1] = 0;

        head = solve17 (head, string, &number_of_elements);
        break;
      }
    case (19):
      {
        fprintf (stdout, "Input:  ");
        if (!fgets (string, MAX_LENGTH, stdin))
          {
            fprintf (stdout, "Cannot read!\n");
            delete head;
            return -1;
          }
        string[strlen (string) - 1] = 0;
        head = solve19  (head, string, &number_of_elements);
        break;
      }
    case (21):
      {
        head = solve21  (head, &number_of_elements);
        break;
      }
    case (23):
      {
        head = solve23  (head, &number_of_elements);
        break;
      }
    case (25):
      {
        fprintf (stdout, "Input:  ");
        if (!fgets (string, MAX_LENGTH, stdin))
          {
            fprintf (stdout, "Cannot read!\n");
            delete head;
            return -1;
          }
        string[strlen (string) - 1] = 0;
        head = solve25  (head, string, &number_of_elements);
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
        head = solve27_1 (head, string, &number_of_elements);
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
  head->print_list (stdout, number_of_elements);
  fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);
  delete head;
  return 0;
}
