#include "read.h"

int read (const char *name, double *array, int n)
{
  FILE *fp;

  if (!(fp = fopen (name, "r")))
    {
      return -1;
    }

  for (int idx = 0; idx < n; idx++)
    {
      if (fscanf (fp, "%lf", array + idx) != 1)
        {
          if (!feof (fp))
            {
              fclose (fp);
              return -2;
            }
          fclose (fp);
          if (idx == 0)
            {
              return -3;
            }
          return -4;
        }
    }
  fclose(fp);
  return 0;
}

void init_array (double *array, int n)
{

  for (int idx = 0; idx < n; idx++)
    {
      array[idx] = init_element (idx);
    }
  return;
}

double init_element (int idx)
{
  (void) idx;
  return rand () % MAX_VALUE;
}


void print_array (double *array, int n)
{
  int left_board = (n > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : n),
      right_board = ((n - left_board) > left_board ? n - left_board : left_board);

  fprintf (stdout, "ARRAY:\n");

  for (int idx = 0; idx < left_board; idx++)
    {
      fprintf (stdout, " %5.2f\n", array[idx]);
    }

  if (2 * MAX_PRINTABLE_NUMBER < n)
    {
      fprintf (stdout, "  .  .  .  .  \n");
    }
  for (int idx = right_board; idx < n; idx++)
    {
      fprintf (stdout, " %5.2f\n", array[idx]);
    }
  fprintf (stdout, "\n");
  return;
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
    case (-4):
      {
        fprintf (stdout, "Not enough elements in [%s]!\n", name);
        break;
      }
    default:
      {
        fprintf (stdout, "Unknown Error %d in [%s]!\n", result, name);
      }
    }
  return;
}
