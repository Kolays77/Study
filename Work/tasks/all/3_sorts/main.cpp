#include "head.h"
#include "read.h"

int main (int argc, char *argv[])
{
  srand (time (0));
  char *file_name = 0;
  int task_number;
  int n = 0, m = 0;
  int result = 0;
  double *array = 0;

  char *file_name2 = 0;
  double *array2 = 0, *result_array = 0;

  double counter_of_time = 0;

  if (argc < 2 || (task_number = atoi (argv[1])) < 0)
    {
      fprintf (stdout, "Cannot read [#]!\n");
      return 1;
    }
  if ((task_number != 2 && task_number != 3)
      && argc != 4 && argc != 3)
    {
      fprintf (stdout, "Usage: %s [#] [n] [<file_name>]\n", argv[0]);
      return -1;
    }
  else if ((task_number == 2 || task_number == 3)
           && argc != 6 && argc != 4)
    {
      fprintf (stdout, "Usage: %s [2] [n] [m] [<file_name1>] [<file_name2>]\n", argv[0]);
      return -1;
    }

  if ((task_number = atoi (argv[1])) <= 0)
    {
      fprintf (stdout, "Cannot read [#]!\n");
      return 1;
    }

  if ((n = atoi (argv[2])) <= 0)
    {
      fprintf (stdout, "Cannot read [n]!\n");
      return 1;
    }

  array = new double [n];
  if (!array)
    {
      fprintf (stdout, "Not enough memory!\n");
      return 2;
    }

  if (task_number != 2 && task_number != 3)
    {
      if (argc == 4)
        {
          file_name = argv[3];
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
    }
  else
    {
      if ((m = atoi (argv[3])) <= 0)
        {
          fprintf (stdout, "Cannot read [m]!\n");
          return 1;
        }
      array2 = new double [m];
      result_array = new double [n + m];
      if (!array2 || !result_array)
        {
          fprintf (stdout, "Not enough memory!\n");
        }

      if (argc == 6)
        {

          file_name = argv[4];
          result = read (file_name, array, n);
          if (result < 0)
            {
              return_error (result, file_name);
              delete [] array;
              delete [] array2;
              delete [] result_array;
              return 3;
            }
          file_name2 = argv[5];
          result = read (file_name2, array2, m);
          if (result < 0)
            {
              return_error (result, file_name2);
              delete [] array;
              delete [] array2;
              delete [] result_array;
              return 3;
            }
        }
      else
        {
          init_array (array, n);
          init_array (array2, n);
        }
      fprintf (stdout, "THE FIRST "); print_array (array, n);
      fprintf (stdout, "THE SECOND "); print_array (array2, m);
    }


  counter_of_time = clock ();

  switch (task_number)
    {
    case 1:
      {
        double element;
        if (!is_increasing (array, n))
          {
            fprintf (stdout, "The sequence is not increasing!\n");
            break;
          }
        fprintf (stdout, "Input [element]:  ");
        if (fscanf (stdin, "%lf", &element) != 1)
          {
            fprintf (stdout, "Cannot read [element]!\n");
            return 1;
          }
        result = binsearch (array, n, element);
        fprintf (stdout, "The new element could be inserted to %d position\n", result);
        break;
      }

    case 2:
      {
        if (!is_increasing (array, n))
          {
            fprintf (stdout, "The sequence in [%s] is not incresing\n", file_name);
            delete [] array2;
            delete [] result_array;
            break;
          }
        if (!is_increasing (array2, m))
          {
            fprintf (stdout, "The sequence in [%s] is not incresing\n", file_name2);
            delete [] array2;
            delete [] result_array;
            break;
          }
        merge (array, array2, n, m, result_array);

        print_array (result_array, n + m);

        delete [] array2;
        delete [] result_array;
        break;
      }

    case 3:
      {
        if (!is_increasing (array, n))
          {
            fprintf (stdout, "The sequence in [%s] is not incresing\n", file_name);
            delete [] array2;
            delete [] result_array;
            break;
          }
        if (!is_increasing (array2, m))
          {
            fprintf (stdout, "The sequence in [%s] is not incresing\n", file_name2);
            delete [] array2;
            delete [] result_array;
            break;
          }
        result = merge_union (array, array2, n, m, result_array);

        print_array (result_array, result);

        delete [] array2;
        delete [] result_array;
        break;
      }

    case 4:
      {
        bubble_sort (array, n);
        print_array (array, n);
        break;
      }

    case 5:
      {
        find_sort (array, n);
        print_array (array, n);
        break;
      }

    case 6:
      {
        insertion_sort (array, n);
        print_array (array, n);
        break;
      }

    case 7:
      {
        binary_insertion_sort (array, n);
        print_array (array, n);
        break;
      }

    case 8:
      {
        array2 = new double [n];
        if (!array2)
          {
            fprintf (stdout, "Not enough memory!\n");
            delete [] array;
            return 2;
          }
        merge_sort (array, array2, n);
        print_array (array, n);
        delete [] array2;
        break;
      }

    case 9:
      {
        quick_sort (array, n);
        print_array (array, n);
        break;
      }

    case 10:
      {
        heap_sort (array, n);
        print_array (array, n);
        break;
      }

    default:
      {
        fprintf (stdout, "There is no task with number [%d]!\n", task_number);
        break;
      }
    }

  counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;
  fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);
  delete [] array;
  return 0;
}
