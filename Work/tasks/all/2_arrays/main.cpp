#include "head.h"
#include "read.h"

int main (int argc, char *argv[])
{
  char *file_name = 0;
  int task_number;
  int n;
  int result = 0;
  double *array = 0;

  if (argc < 2 || (task_number = atoi (argv[1])) < 0)
    {
      fprintf (stdout, "Cannot read [#]!\n");
      return 1;
    }
  if (task_number != 5 && argc != 4 && argc != 3)
    {
      fprintf (stdout, "Usage: %s [#] [n] [<file_name>]\n", argv[0]);
      return -1;
    }

  if (task_number == 5 && argc != 5)
    {
      fprintf (stdout, "Usage: %s [5] [n] [file_name <0>] [file_name2]\n", argv[0]);
      return -1;
    }
  if (task_number >= MAX_TASK_NUMBER)
    {
      fprintf (stdout, "There is no task with number [%d]!\n", task_number);
      return 2;
    }

  if ((n = atoi (argv[2])) <= 0)
    {
      fprintf (stdout, "Cannot read [n]!\n");
      return 1;
    }
  if (argc > 3)
    {
      file_name = argv[3];
    }
  array = new double [n];
  if (!array)
    {
      fprintf (stdout, "Not enough memory!\n");
      return 2;
    }
  if (file_name)
    {
      result = read (file_name, array, n);
      if (result < 0)
        {
          return_error (result, file_name);
          delete [] array;
          return 3;
        }
    }
  else
    {
      init_array (array, n);
    }
  print_array (array, n);

  switch (task_number)
    {
    case 1:
      {
        replace_by_average (array, n);
        print_array (array, n);
        break;
      }

    case 2:
      {
        double barrier;
        fprintf (stdout, "Input [element]:   ");
        if (fscanf (stdin, "%lf", &barrier) != 1)
          {
            fprintf (stdout, "Cannot read [element]!\n");
            delete [] array;
            return 1;
          }
        swap_elements_for_qsort (array, n, barrier);
        print_array (array, n);
        break;
      }

    case 3:
      {
        shift_right (array, n);
        print_array (array, n);
        break;
      }

    case 4:
      {
        int shift;
        fprintf (stdout, "Input [k]:  ");
        if (fscanf (stdin, "%d", &shift) != 1)
          {
            fprintf (stdout, "Cannot read [k]!\n");
            delete [] array;
            return 1;
          }
        cyclic_shift (array, n, shift);
        print_array (array, n);
        break;
      }

    case 5:
      {
        const char *file_sequence = argv[4];
        result = count_subsections (array, file_sequence, n);
        if (result < 0)
          {
            return_error (result, file_sequence);
          }
        else if (result == 0)
          {
            fprintf (stdout, "There is no sequence in [%s]\n", file_sequence);
          }
        else
          {
            fprintf (stdout, "The sequence occurs in [%s] %d times\n", file_sequence, result);
          }
        break;
      }

    case 6:
      {
        double barrier;

        fprintf (stdout, "Input [element]:  ");
        if (fscanf (stdin, "%lf", &barrier) != 1)
          {
            fprintf (stdout, "Cannot read [barrier]!\n");
            return 1;
          }

        result = delete_little_elememts (array, n, barrier);
        print_array (array, result);
        break;
      }

    default:
      {
        fprintf (stdout, "There is no task with number [%d]!\n", task_number);
        break;
      }
    }

  delete [] array;
  return 0;
}
