#include "head.h"


int main (int argc, char *argv[])
{
  char *file_name = 0;
  int task_number;
  int result = 0;

  if (argc < 2 || (task_number = atoi (argv[1])) <= 0)
    {
      fprintf (stdout, "Cannot read [#]!\n");
      return 1;
    }
  if (task_number != 6 && task_number != 10 && argc != 3)
    {
      fprintf (stdout, "Usage: %s [#] [file_name]\n", argv[0]);
      return 1;
    }
  else if (task_number == 6 && argc != 4)
    {
      fprintf (stdout, "Usage: %s [6] [file_name1] [file_name2]\n", argv[0]);
      return 1;
    }
  if (argc > 2)
    {
      file_name = argv[2];
    }

  switch (task_number)
    {
    case 1:
      {
        result = count_maximums (file_name);
        if (result < 0)
          {
            return_error (result, file_name);
          }
        else
          {
            fprintf (stdout, "The number of maximums is %d\n", result);
          }
        break;
      }

    case 2:
      {
        result = count_local_maximums (file_name);
        if (result < 0)
          {
            return_error (result, file_name);
          }
        else
          {
            fprintf (stdout, "The number of local maximums is %d\n", result);
          }
        break;
      }

    case 3:
      {
        result = characterize_sequence (file_name);
        switch (result)
          {
          case 0:
            fprintf (stdout, "The sequence is not monotonic\n");
            break;
          case 1:
            fprintf (stdout, "The sequence is increasing\n");
            break;
          case 2:
            fprintf (stdout, "The sequence is decreasing\n");
            break;
          case 3:
            fprintf (stdout, "The sequence is monotonic\n");
            break;
          case 4:
            fprintf (stdout, "Not enough data\n");
            break;
          default:
            return_error (result, file_name);
            break;
          }
        break;
      }

    case 4:
      {
        result = is_fibonachi (file_name);
        switch (result)
          {
          case 0:
            fprintf (stdout, "The sequence is not fibonachi\n");
            break;
          case 1:
            fprintf (stdout, "The sequense is fibonachi\n");
            break;
          default:
            return_error (result, file_name);
            break;
          }
        break;
      }

    case 5:
      {
        result = is_reverse_fibonachi (file_name);
        switch (result)
          {
          case 0:
            fprintf (stdout, "The sequence is not reverse fibonachi\n");
            break;
          case 1:
            fprintf (stdout, "The sequense is reverse fibonachi\n");
            break;
          default:
            return_error (result, file_name);
            break;
          }
        break;
      }

    case 6:
      {
        char *file_name2;
        file_name2 = argv[3];
        result = check_two_sequences (file_name, file_name2);
        switch (result)
          {
          case 0:
            fprintf (stdout, "Two sequences are \"BAD\"\n");
            break;
          case 1:
            fprintf (stdout, "Two sequences are \"GOOD\"\n");
            break;
          case 2:
            fprintf (stdout, "There is not enough elements in [%s]\n", file_name);
            break;
          default:
            if (result & 1)
              {
                return_error (result / 10, file_name);
              }
            else
              {
                return_error (result / 10, file_name2);
              }
            break;
          }
        break;
      }

    case 7:
      {
        double deviation = 0;
        result = standard_deviation (file_name, &deviation);
        if (result <= 0)
          {
            return_error (result, file_name);
          }
        else
          {
            fprintf (stdout, "The number of elements is %d\n", result);
            fprintf (stdout, "The Standard Deviation is %lf\n", deviation);
          }
        break;
      }

    case 8:
      {
        result = type_of_progression (file_name);
        switch (result)
          {
          case 0:
            fprintf (stdout, "The sequence is not a progression\n");
            break;
          case 1:
            fprintf (stdout, "The progression is arithmetic\n");
            break;
          case 2:
            fprintf (stdout, "The progression is geometric\n");
            break;
          case 3:
            fprintf (stdout, "The sequence is monotonic\n");
            break;
          case 4:
            fprintf (stdout, "Not enough data\n");
            break;
          default:
            return_error (result, file_name);
            break;
          }
        break;
      }

    case 9:
      {
        double max = 0;
        int first = 0, last = 0;
        result = get_indeces_of_maximums (file_name, &max, &first, &last);
        if (result < 0)
          {
            return_error (result, file_name);
          }
        else
          {
            fprintf (stdout, "The maximum is %.3f\n", max);
            if (last - first)
              {
                fprintf (stdout, "The first position is %d and the last is %d\n", first, last);
              }
            else
              {
                fprintf (stdout, "This is only one in position %d\n", first);
              }
          }
        break;
      }

    case 10:
      {
        double barrier = 0;
        int first = 0, last = 0;
        fprintf (stdout, "Input element:  ");
        if (fscanf (stdin, "%lf", &barrier) != 1)
          {
            fprintf (stdout, "Cannot read [element]!\n");
            return -1;
          }
        result = get_indeces_of_barrier (file_name, barrier, &first, &last);
        if (result < 0)
          {
            return_error (result, file_name);
          }
        else if (result == 0)
          {
            fprintf (stdout, "There is no %.3f in %s\n", barrier, file_name);
          }
        else
          {
            if (last - first)
              {
                fprintf (stdout, "The first position is %d and the last is %d\n", first, last);
              }
            else
              {
                fprintf (stdout, "This is only one in position %d\n", first);
              }
          }
        break;
      }

    default:
      fprintf (stdout, "There is no task with number [%d]!\n", task_number);
      break;
    }
  return 0;
}


void return_error (int result, const char *name)
{
  switch (result)
    {
    case (-1):
      {
        fprintf (stdout, "Cannot open [%s]!\n", name);
        break;
      }
    case (-2):
      {
        fprintf (stdout, "Cannot read [%s]!\n", name);
        break;
      }
    case (-3):
      {
        fprintf (stdout, "[%s] is empty!\n", name);
        break;
      }
    default:
      {
        fprintf (stdout, "Unknown Error %d in [%s]!\n", result, name);
      }
    }
  return;
}
