#include "read.h"

int read (const char *name, double *x, double *y, int n)
{
  FILE *fp;

  if (!(fp = fopen (name, "r")))
    {
      return -1;
    }

  for (int idx = 0; idx < n; idx++)
    {
      if (fscanf (fp, "%lf", x + idx) != 1)
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
      if (fscanf (fp, "%lf", y + idx) != 1)
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
  fclose (fp);
  return 0;
}

int read (const char *name, double *x, double *y, double *dif, int n)
{
  FILE *fp;
  int idx;

  if (!(fp = fopen(name, "r")))
    {
      return -1;
    }

  for (idx = 0; idx < n; idx++)
    {
      if (fscanf (fp, "%lf", x + idx) != 1)
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
      if (fscanf (fp, "%lf", y + idx) != 1)
        {
          if (!feof(fp))
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
      if (fscanf (fp, "%lf", dif + idx) != 1)
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
  fclose (fp);
  return 0;
}

void print_function (double *x, double *y, int n)
{
  int left_board = (n > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : n),
      right_board = ((n - left_board) > left_board ? n - left_board : left_board);

  fprintf (stdout, "FUNCTION:\n");
  for (int idx = 1; idx < left_board; idx++)
    {
      fprintf (stdout, "f(%.2f) = %.2f\n", x[idx], y[idx]);
    }
  if (2 * MAX_PRINTABLE_NUMBER < n)
    {
      fprintf (stdout, " ...\n");
    }
  for (int idx = right_board; idx < n; idx++)
    {
      fprintf (stdout, "f(%.2f) = %.2f\n", x[idx], y[idx]);
    }
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
