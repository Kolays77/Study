#include "read.h"

int read_matrix (const char *name, double *matrix, int row, int column)
{
  FILE *fp;

  if (!(fp = fopen (name, "r")))
    {
      return -1;
    }

  for (int idx1 = 0; idx1 < row; idx1++)
    {
      for (int idx2 = 0; idx2 < column; idx2++)
        {
          if (fscanf (fp, "%lf", matrix + idx1 * column + idx2) != 1)
            {
              if (!feof (fp))
                {
                  fclose (fp);
                  return -2;
                }
              fclose (fp);
              if (idx1 == 0 && idx2 == 0)
                {
                  return -3;
                }
              return -4;
            }
        }
    }
  fclose (fp);
  return 0;
}

void init_matrix (double *matrix, int row, int column)
{
  for (int idx1 = 0; idx1 < row; idx1++)
    {
      for (int idx2 = 0; idx2 < column; idx2++)
        {
          matrix[idx1 * column + idx2] = init_element (idx1, idx2);
        }
    }
  return;
}

double init_element (int idx1, int idx2)
{
  (void) idx1; (void) idx2;
  return idx1 - idx2 + 1;
}

void print_matrix (double *matrix, int row, int column)
{
  int left_board1 = (row > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : row),
      right_board1 = ((row - left_board1) > left_board1 ? row - left_board1 : left_board1),
      left_board2 = (column > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : column),
      right_board2 = ((column - left_board2) > left_board2 ? column - left_board2 : left_board2);

  fprintf (stdout, "MATRIX:\n     ");

  for (int idx2 = 0; idx2 < left_board2; idx2++)
    {
      fprintf (stdout, "   [%4d]", idx2);
    }
  if (2 * MAX_PRINTABLE_NUMBER < column)
    {
      fprintf (stdout, "   ... ");
    }
  for (int idx2 = right_board2; idx2 < column; idx2++)
    {
      fprintf (stdout, "   [%4d]", idx2);
    }
  fprintf (stdout, "\n");


  for (int idx1 = 0; idx1 < left_board1; idx1++)
    {
      fprintf (stdout, "[%4d]"	, idx1);
      for (int idx2 = 0; idx2 < left_board2; idx2++)
        {
          fprintf (stdout, " %7.2f ", matrix[idx1 * column + idx2]);
        }
      if (2 * MAX_PRINTABLE_NUMBER < column)
        {
          fprintf (stdout, "  ...  ");
        }
      for (int idx2 = right_board2; idx2 < column; idx2++)
        {
          fprintf (stdout, " %7.2f ", matrix[idx1 * column + idx2]);
        }
      fprintf (stdout, "\n");
    }

  if (2 * MAX_PRINTABLE_NUMBER < row)
    {
      for (int tmp = 0; tmp < 3; tmp++)
        {
          fprintf (stdout, "     ");
          for (int idx1 = 0; idx1 < left_board1; idx1++)
            {
              fprintf (stdout, "      ...");
            }
          if (2 * MAX_PRINTABLE_NUMBER < column)
            {
              fprintf (stdout, "   ... ");
            }
          for (int idx2 = right_board2; idx2 < column; idx2++)
            {
              fprintf (stdout, "      ...");
            }
          fprintf (stdout, "\n");
        }
    }
  for (int idx1 = right_board1; idx1 < row; idx1++)
    {
      fprintf (stdout, "[%4d]", idx1);
      for (int idx2 = 0; idx2 < left_board2; idx2++)
        {
          fprintf (stdout, " %7.2f ", matrix[idx1 * column + idx2]);
        }
      if (2 * MAX_PRINTABLE_NUMBER < column)
        {
          fprintf (stdout, "  ...  ");
        }
      for (int idx2 = right_board2; idx2 < column; idx2++)
        {
          fprintf (stdout, " %7.2f ", matrix[idx1 * column + idx2]);
        }
      fprintf (stdout, "\n");
    }
  fprintf (stdout, "\n");
  return;
}




int read_vector (const char *name, double *vector, int n)
{
  FILE *fp;
  if (!(fp = fopen (name, "r")))
    {
      return -1;
    }
  for (int idx = 0; idx < n; idx++)
    {
      if (fscanf (fp, "%lf", vector + idx) != 1)
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

void print_vector (double *vector, int n)
{
  int left_board = (n > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : n),
      right_board = ((n - left_board) > left_board ? n - left_board : left_board);

  fprintf (stdout, "VECTOR:\n      (%5.2f", vector[0]);
  for (int idx = 1; idx < left_board; idx++)
    {
      fprintf (stdout, ", %5.2f", vector[idx]);
    }
  if (2 * MAX_PRINTABLE_NUMBER < n)
    {
      fprintf (stdout, "   ... ");
    }
  for (int idx = right_board; idx < n; idx++)
    {
      fprintf (stdout, ", %5.2f", vector[idx]);
    }
  fprintf (stdout, ")\n\n");
  return;
}

void init_vector (double *vector, int length)
{
  for (int idx = 0; idx < length; idx++)
    {
      vector[idx] = init_element (idx);
    }
  return;
}



double init_element (int idx)
{
  (void) idx;
  return idx;
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
