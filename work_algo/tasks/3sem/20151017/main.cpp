#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "read.h"
#include "solve.h"
#include "generate.h"

#define MAX_LENGTH 1000
int main (int argc, char **argv)
{
  const char *file_name1 = "a.txt", *file_name2 = "b.txt";
  char name[MAX_LENGTH]; int value = 0;
  int result, index, n = 0, k = 0;
  double counter_of_time;
  student_list *head = 0, *sub_list = 0;

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
  sub_list = new student_list;
  if (argc == 2)
    {
      result = read_list (file_name1, head);
      if (result < 0)
        {
          return_error (result, file_name1);
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
  fprintf (stdout, "#%d\n", index);

  switch (index)
    {
    case (1):
      student *element;
      fprintf (stdout, "Input student:\n");
      if (!fgets (name, MAX_LENGTH, stdin))
        {
          fprintf (stdout, "Cannot read name!\n");
          delete head;
          return -1;
        }
      fprintf (stdout, "Input value:\n");
      if (fscanf (stdin, "%d", &value) != 1)
        {
          fprintf (stdout, "Cannot read value!\n");
          delete head;
          return -1;
        }
      element = new student (name, 1);
      head = make_new_list1 (head, element);
      delete element;
      break;

    case (2):
      fprintf (stdout, "Input [k]:\n");
      if (fscanf (stdin, "%d", &k) != 1)
        {
          fprintf (stdout, "Cannot read [k]!\n");
          delete head;
          return -1;
        }

      k %= n;
      if (k < 0)
        {
          k = n + k;
        }
      head = make_shift2 (head, n - k);
      break;

    case (3):
      head = delete_less (head, &n);
      break;

    case (4):
      head = delete_more (head, &n);
      break;

    case (5):
      fprintf (stdout, "Input [k]:\n");
      if (fscanf (stdin, "%d", &k) != 1)
        {
          fprintf (stdout, "Cannot read [k]!\n");
          delete head;
          return -1;
        }
      if (k >= n || k <= 0)
        {
          fprintf (stdout, "[k] must be in [1..n-1]!\n");
          delete head;
          return -1;
        }
      head = delete_more_k (head, k, &n);
      break;

    case (6):
      head = delete_dicreasing (head, &n);
      break;

    case (7):
      head = delete_increasing (head, &n);
      break;

    case (8):
      fprintf (stdout, "Input [k]:\n");
      if (fscanf (stdin, "%d", &k) != 1)
        {
          fprintf (stdout, "Cannot read [k]!\n");
          delete head;
          return -1;
        }
      if (k <= 0)
        {
          fprintf (stdout, "[k] must be more than 0!\n");
          delete head;
          return -1;
        }
      head = delete_monotonic (head, k, &n);
      break;

    case (9):
      int key, len_sub_list;
      if (argc == 2)
        {
          result = read_list (file_name2, sub_list);
          if (result < 0)
            {
              return_error (result, file_name2);
              delete sub_list;
              delete head;
              return -1;
            }
        }
      if (argc == 3)
        {
          fprintf (stdout, "Should I read from %s [0] or generate [len] the second list? : ", file_name2);
          if (fscanf (stdin, "%d", &key) != 1 || key < 0)
            {
              fprintf (stdout, "Cannot read [key]!\n");
              delete head;
              delete sub_list;
              return -2;
            }
          if (key == 0)
            {
              result = read_list (file_name2, sub_list);
              if (result < 0)
                {
                  return_error (result, file_name2);
                  delete head;
                  delete sub_list;
                  return -1;
                }
            }
          else
            {
              result = generate (sub_list, key);
              if (result < 0)
                {
                  fprintf (stdout, "Unknown error %d in generating list", result);
                  delete head;
                  delete sub_list;
                  return -3;
                }
            }
        }
      len_sub_list = result;
      fprintf (stdout, "SUB_");
      sub_list->print_list (len_sub_list);
      head = delete_sublist (head, sub_list, &n, &len_sub_list);
      break;
    }
  counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
  fprintf (stdout, "NEW ");
  head->print_list (n);
  fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);
  delete sub_list;
  delete head;
  return 0;
}
