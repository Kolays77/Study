#include "head.h"

int main (int argc, char *argv[])
{
  char string1[LENGTH], string2[LENGTH];
  char *file1 = 0, *file2 = 0;
  int task_number;
  int result;

  if (argc != 4)
    {
      fprintf (stdout, "Usage: %s [#] [file1] [file2]\n", argv[0]);
      return 1;
    }
  if ((task_number = atoi (argv[1])) <= 0)
    {
      fprintf (stdout, "Cannot read [#]!\n");
      return 1;
    }
  file1 = argv[2];
  file2 = argv[3];
  fprintf (stdout, "Input string:  ");
  if (!fgets (string1, LENGTH, stdin))
    {
      fprintf (stdout, "Cannot read string!\n");
      return -1;
    }
  make_string (string1);
  if (task_number == 1 || task_number == 2 || task_number == 3 || task_number == 4 ||task_number == 5)
    {
      fprintf (stdout, "Input string2:  ");
      if (!fgets (string2, LENGTH, stdin))
        {
          fprintf (stdout, "Cannot read new string!\n");
          return -1;
        }
      make_string (string2);
    }

  switch (task_number)
    {
    case 1:
      {
        result = replace_substrings_by_others (file1, file2, string1, string2);
        if (result < 0)
          {
            if (result <= -20)
              {
                return_error (result % 10, file2);
              }
            else
              {
                return_error (result % 10, file1);
              }
          }
        else
          {
            fprintf (stdout, "%d strings were changed\n", result);
          }
        break;
      }

    case 2:
      {
        result = find_not_equals_without_spaces (file1, file2, string1, string2);
        if (result < 0)
          {
            if (result <= -20)
              {
                return_error (result % 10, file2);
              }
            else
              {
                return_error (result % 10, file1);
              }
          }
        else
          {
            fprintf (stdout, "There are %d strings not equal with this\n", result);
          }
        break;
      }

    case 3:
      {
        result = find_consists_of_allowable_chars (file1, file2, string1, string2);
        if (result < 0)
          {
            if (result <= -20)
              {
                return_error (result % 10, file2);
              }
            else
              {
                return_error (result % 10, file1);
              }
          }
        else
          {
            fprintf (stdout, "There are %d strings consisting of this chars\n", result);
          }
        break;
      }

    case 4:
      {
        result = find_includes_substring (file1, file2, string1, string2);
        if (result < 0)
          {
            if (result <= -20)
              {
                return_error (result % 10, file2);
              }
            else
              {
                return_error (result % 10, file1);
              }
          }
        else
          {
            fprintf (stdout, "There are %d strings comprising this substring\n", result);
          }
        break;
      }

    case 5:
      {
        result = find_includes_words (file1, file2, string1, string2);
        if (result < 0)
          {
            if (result <= -20)
              {
                return_error (result % 10, file2);
              }
            else
              {
                return_error (result % 10, file1);
              }
          }
        else
          {
            fprintf (stdout, "There are %d strings comprising not at least one of this word\n", result);
          }
        break;
      }

    case 6:
      {
        result = find_equals_strings1 (file1, file2, string1);
        if (result < 0)
          {
            if (result <= -20)
              {
                return_error (result % 10, file2);
              }
            else
              {
                return_error (result % 10, file1);
              }
          }
        else
          {
            fprintf (stdout, "There are %d strings equal to this\n", result);
          }
        break;
      }

    case 7:
      {
        result = find_equals_strings2 (file1, file2, string1);
        if (result < 0)
          {
            if (result <= -20)
              {
                return_error (result % 10, file2);
              }
            else
              {
                return_error (result % 10, file1);
              }
          }
        else
          {
            fprintf (stdout, "There are %d strings equal to this\n", result);
          }
        break;
      }

    case 8:
      {
        result = find_equals_strings3 (file1, file2, string1);
        if (result < 0)
          {
            if (result <= -20)
              {
                return_error (result % 10, file2);
              }
            else
              {
                return_error (result % 10, file1);
              }
          }
        else
          {
            fprintf (stdout, "There are %d strings equal to this\n", result);
          }
        break;
      }

    default:
      {
        fprintf (stdout, "There is no task with number [%d]\n", task_number);
        return 1;
      }
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
    default:
      {
        fprintf (stdout, "Unknown Error %d!\n", result);
      }
    }
  return;
}
