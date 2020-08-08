#include "head.h"

int main (int argc, char *argv[])
{
  int result, task_number = 0;
  double counter_of_time, answer, eps;
  int deg = 0;
  double (*f) (double),
      (*dif) (double);

  if (argc < 2 || (task_number = atoi (argv[1])) <= 0)
    {
      fprintf (stdout, "Cannot read [#]!\n");
      return 2;
    }
  if (task_number != 6 && argc != 2)
    {
      fprintf (stdout, "Usage: %s [#]\n", argv[0]);
      return 1;
    }
  if (task_number == 6)
    {
      if (argc != 3)
        {
          fprintf (stdout, "Usage: %s [#] [m]\n", argv[0]);
          return 1;
        }
      if ((deg = atoi (argv[2])) <= 0)
        {
          fprintf (stdout, "Cannot read [m]!\n");
          return 2;
        }
    }

  fprintf (stdout, "Input [eps]: ");
  if (fscanf (stdin, "%lf", &eps) != 1)
    {
      fprintf (stdout, "Cannot read [eps] !\n");
      return 1;
    }
  if (eps < 0)
    {
      fprintf (stdout, "[eps] must be more than 0!\n");
      return 2;
    }
  f = &function;
  dif = &differential;


  switch (task_number)
    {
    case 1:
      {
        double left_board, right_board;
        fprintf (stdout, "Input [left_board]: ");
        if (fscanf (stdin, "%lf", &left_board) != 1)
          {
            fprintf (stdout, "Cannot read!\n");
            return 1;
          }
        fprintf (stdout, "Input [right_board]: ");
        if (fscanf (stdin, "%lf", &right_board) != 1)
          {
            fprintf (stdout, "Cannot read!\n");
            return 1;
          }

        if (left_board > right_board)
          {
            double tmp = left_board;
            left_board = right_board;
            right_board = tmp;
          }
        counter_of_time = clock ();
        result = find_root1 (f, left_board, right_board, eps, &answer);
        counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;
        break;
      }
    case 2:
      {
        double start_x;
        fprintf (stdout, "Input [x0]: ");
        if (fscanf (stdin, "%lf", &start_x) != 1)
          {
            fprintf (stdout, "Cannot read!\n");
            return 1;
          }

        counter_of_time = clock ();
        result = find_root2 (f, dif, start_x, eps, &answer);
        counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;
        break;
      }
    case 3:
      {
        double left_board, right_board;
        fprintf (stdout, "Input [a]: ");
        if (fscanf (stdin, "%lf", &left_board) != 1)
          {
            fprintf (stdout, "Cannot read!\n");
            return 1;
          }
        fprintf (stdout, "Input [b]: ");
        if (fscanf (stdin, "%lf", &right_board) != 1)
          {
            fprintf (stdout, "Cannot read!\n");
            return 1;
          }
        counter_of_time = clock ();
        result = find_root3 (f, left_board, right_board, eps, &answer);
        counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;
        break;
      }
    case 4:
      {
        double left_board, right_board;
        fprintf (stdout, "Input [a]: ");
        if (fscanf (stdin, "%lf", &left_board) != 1)
          {
            fprintf (stdout, "Cannot read!\n");
            return 1;
          }
        fprintf (stdout, "Input [b]: ");
        if (fscanf (stdin, "%lf", &right_board) != 1)
          {
            fprintf (stdout, "Cannot read!\n");
            return 1;
          }
        counter_of_time = clock ();
        result = find_root4 (f, left_board, right_board, eps, &answer);
        counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;
        break;
      }
    case 5:
      {
        double x0, x2;
        fprintf (stdout, "Input [x0]: ");
        if (fscanf (stdin, "%lf", &x0) != 1)
          {
            fprintf (stdout, "Cannot read!\n");
            return 1;
          }
        fprintf (stdout, "Input [x1]: ");
        if (fscanf (stdin, "%lf", &x2) != 1)
          {
            fprintf (stdout, "Cannot read!\n");
            return 1;
          }

        counter_of_time = clock ();
        result = find_root5 (f, x0, x2, (x0 + x2) / 2, eps, &answer);
        counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;
        break;
      }

    case 6:
      {
        double left_board, right_board;
        double *dif;
        fprintf (stdout, "Input [a]: ");
        if (fscanf (stdin, "%lf", &left_board) != 1)
          {
            fprintf (stdout, "Cannot read!\n");
            return 1;
          }
        fprintf (stdout, "Input [b]: ");
        if (fscanf (stdin, "%lf", &right_board) != 1)
          {
            fprintf (stdout, "Cannot read!\n");
            return 1;
          }

        dif = new double [3 * deg + 1];
        if (!dif)
          {
            fprintf (stdout, "Not enough memory!\n");
            return 2;
          }

        counter_of_time = clock ();
        result = find_root6 (f, dif, left_board, right_board, deg, eps, &answer);
        counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;
        break;
      }

    case 7:
      {
        double x_start;
        fprintf (stdout, "Input [x]: ");
        if (fscanf (stdin, "%lf", &x_start) != 1)
          {
            fprintf (stdout, "Cannot read!\n");
            return 1;
          }

        counter_of_time = clock ();
        result = find_root7 (f, dif, x_start, eps, &answer);
        counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;
        break;
      }

    case 8:
      {
        double left_board, right_board;
        fprintf (stdout, "Input [a]: ");
        if (fscanf (stdin, "%lf", &left_board) != 1)
          {
            fprintf (stdout, "Cannot read!\n");
            return 1;
          }
        fprintf (stdout, "Input [b]: ");
        if (fscanf (stdin, "%lf", &right_board) != 1)
          {
            fprintf (stdout, "Cannot read!\n");
            return 1;
          }
        counter_of_time = clock ();
        result = find_max8 (f, left_board, right_board, eps, &answer);
        counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;
        break;
      }

    case 9:
      {
        double left_board, right_board;
        fprintf (stdout, "Input [a]: ");
        if (fscanf (stdin, "%lf", &left_board) != 1)
          {
            fprintf (stdout, "Cannot read!\n");
            return 1;
          }
        fprintf (stdout, "Input [b]: ");
        if (fscanf (stdin, "%lf", &right_board) != 1)
          {
            fprintf (stdout, "Cannot read!\n");
            return 1;
          }
        counter_of_time = clock ();
        result = find_max9 (f, left_board, right_board, eps, &answer);
        counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;
        break;
      }

    case 10:
      {
        double x0, x2;
        fprintf (stdout, "Input [x0]: ");
        if (fscanf (stdin, "%lf", &x0) != 1)
          {
            fprintf (stdout, "Cannot read!\n");
            return 1;
          }
        fprintf (stdout, "Input [x1]: ");
        if (fscanf (stdin, "%lf", &x2) != 1)
          {
            fprintf (stdout, "Cannot read!\n");
            return 1;
          }

        counter_of_time = clock ();
        result = find_max10 (f, x0, x2, (x0 + x2) / 2, eps, &answer);
        counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;
        break;
      }


    default:
      {
        fprintf (stdout, "There is no task with number [%d]\n", task_number);
        return 1;
      }
    }

  if (result < 0)
    {
      fprintf (stdout, "Cannot solve!\n");
      return 0;
    }
  fprintf (stdout, "x = %.5f\n", answer);
  if (task_number < 8)
    {
      fprintf (stdout, "f(x) = %e\n", f (answer));
    }
  else
    {
      fprintf (stdout, "f(x) = %.5f\n", f (answer));
    }
  fprintf (stdout, "Iterations = %d\n", result);
  fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);
  return 0;
}
