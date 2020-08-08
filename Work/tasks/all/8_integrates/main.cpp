#include "head.h"

int main (int argc, char *argv[])
{
  int task_number = 0;
  double counter_of_time, answer;
  double (*f) (double);

  if (argc < 2 || (task_number = atoi (argv[1])) <= 0)
    {
      fprintf (stdout, "Cannot read [#]!\n");
      return 2;
    }

  f = &function;


  switch (task_number)
    {
    case 1:
      {
        int n = 1;
        double left_board, right_board;
        while (1)
          {
            fprintf (stdout, "Input [N]: ");
            if (fscanf (stdin, "%d", &n) != 1)
              {
                fprintf (stdout, "Cannot read [n]!\n");
                return 1;
              }
            if (n < 0)
              {
                return 0;
              }
            fprintf (stdout, "Input [a]: ");
            if (fscanf (stdin, "%lf", &left_board) != 1)
              {
                fprintf (stdout, "Cannot read [a]!\n");
                return 1;
              }
            fprintf (stdout, "Input [b]: ");
            if (fscanf (stdin, "%lf", &right_board) != 1)
              {
                fprintf (stdout, "Cannot read [b]!\n");
                return 1;
              }

            counter_of_time = clock ();
            answer = calculate_integral1 (f, left_board, right_board, n);
            counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;

            fprintf (stdout, "Integral = %.10f\n", answer);
            fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);
          }
        break;
      }

    case 2:
      {
        int n = 1;
        double left_board, right_board;
        while (1)
          {
            fprintf (stdout, "Input [N]: ");
            if (fscanf (stdin, "%d", &n) != 1)
              {
                fprintf (stdout, "Cannot read [n]!\n");
                return 1;
              }
            if (n < 0)
              {
                return 0;
              }
            fprintf (stdout, "Input [a]: ");
            if (fscanf (stdin, "%lf", &left_board) != 1)
              {
                fprintf (stdout, "Cannot read [a]!\n");
                return 1;
              }
            fprintf (stdout, "Input [b]: ");
            if (fscanf (stdin, "%lf", &right_board) != 1)
              {
                fprintf (stdout, "Cannot read [b]!\n");
                return 1;
              }

            counter_of_time = clock ();
            answer = calculate_integral2 (f, left_board, right_board, n);
            counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;

            fprintf (stdout, "Integral = %.10f\n", answer);
            fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);
          }
        break;
      }

    case 3:
      {
        int n = 1;
        double left_board, right_board;
        while (1)
          {
            fprintf (stdout, "Input [N]: ");
            if (fscanf (stdin, "%d", &n) != 1)
              {
                fprintf (stdout, "Cannot read [n]!\n");
                return 1;
              }
            if (n < 0)
              {
                return 0;
              }
            fprintf (stdout, "Input [a]: ");
            if (fscanf (stdin, "%lf", &left_board) != 1)
              {
                fprintf (stdout, "Cannot read [a]!\n");
                return 1;
              }
            fprintf (stdout, "Input [b]: ");
            if (fscanf (stdin, "%lf", &right_board) != 1)
              {
                fprintf (stdout, "Cannot read [b]!\n");
                return 1;
              }

            counter_of_time = clock ();
            answer = calculate_integral3 (f, left_board, right_board, n);
            counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;

            fprintf (stdout, "Integral = %.10f\n", answer);
            fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);
          }
        break;
      }

    case 4:
      {
        int n = 1;
        double left_board, right_board;
        while (1)
          {
            fprintf (stdout, "Input [N]: ");
            if (fscanf (stdin, "%d", &n) != 1)
              {
                fprintf (stdout, "Cannot read [n]!\n");
                return 1;
              }
            if (n < 0)
              {
                return 0;
              }
            fprintf (stdout, "Input [a]: ");
            if (fscanf (stdin, "%lf", &left_board) != 1)
              {
                fprintf (stdout, "Cannot read [a]!\n");
                return 1;
              }
            fprintf (stdout, "Input [b]: ");
            if (fscanf (stdin, "%lf", &right_board) != 1)
              {
                fprintf (stdout, "Cannot read [b]!\n");
                return 1;
              }

            counter_of_time = clock ();
            answer = calculate_integral4 (f, left_board, right_board, n);
            counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;

            fprintf (stdout, "Integral = %.10f\n", answer);
            fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);
          }
        break;
      }

    case 5:
      {
        double eps = 1;
        double left_board, right_board;
        int result;
        while (1)
          {
            fprintf (stdout, "Input [eps]: ");
            if (fscanf (stdin, "%lf", &eps) != 1)
              {
                fprintf (stdout, "Cannot read [eps]!\n");
                return 1;
              }
            if (eps < 0)
              {
                return 0;
              }
            fprintf (stdout, "Input [a]: ");
            if (fscanf (stdin, "%lf", &left_board) != 1)
              {
                fprintf (stdout, "Cannot read [a]!\n");
                return 1;
              }
            fprintf (stdout, "Input [b]: ");
            if (fscanf (stdin, "%lf", &right_board) != 1)
              {
                fprintf (stdout, "Cannot read [b]!\n");
                return 1;
              }

            counter_of_time = clock ();
            result = calculate_integral5 (f, left_board, right_board, eps, &answer);
            counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;

            if (result < 0)
              {
                fprintf (stdout, "Cannot solve!\n");
                continue;
              }
            fprintf (stdout, "Integral = %.10f\n", answer);
            fprintf (stdout, "Iterations = %d\n", result);
            fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);
          }
        break;
      }

    case 6:
      {
        double eps = 1;
        double left_board, right_board;
        int result;
        while (1)
          {
            fprintf (stdout, "Input [eps]: ");
            if (fscanf (stdin, "%lf", &eps) != 1)
              {
                fprintf (stdout, "Cannot read [eps]!\n");
                return 1;
              }
            if (eps < 0)
              {
                return 0;
              }
            fprintf (stdout, "Input [a]: ");
            if (fscanf (stdin, "%lf", &left_board) != 1)
              {
                fprintf (stdout, "Cannot read [a]!\n");
                return 1;
              }
            fprintf (stdout, "Input [b]: ");
            if (fscanf (stdin, "%lf", &right_board) != 1)
              {
                fprintf (stdout, "Cannot read [b]!\n");
                return 1;
              }

            counter_of_time = clock ();
            result = calculate_integral6 (f, left_board, right_board, eps, &answer);
            counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;

            if (result < 0)
              {
                fprintf (stdout, "Cannot solve!\n");
                break;
              }
            fprintf (stdout, "Integral = %.10f\n", answer);
            fprintf (stdout, "Iterations = %d\n", result);
            fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);
          }
        break;
      }

    case 7:
      {
        double eps = 1;
        double start_board;
        double result;
        while (1)
          {
            fprintf (stdout, "Input [eps]: ");
            if (fscanf (stdin, "%lf", &eps) != 1)
              {
                fprintf (stdout, "Cannot read [eps]!\n");
                return 1;
              }
            if (eps < 0)
              {
                return 0;
              }
            fprintf (stdout, "Input [x0]: ");
            if (fscanf (stdin, "%lf", &start_board) != 1)
              {
                fprintf (stdout, "Cannot read [x0]!\n");
                return 1;
              }

            counter_of_time = clock ();
            result = calculate_integral7 (f, start_board, eps, &answer);
            counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;

            if (result < 0)
              {
                fprintf (stdout, "Cannot solve!\n");
                continue;
              }
            fprintf (stdout, "Integral = %.10f\n", answer);
            fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);
          }
        break;
      }

    case 8:
      {
        double eps = 1;
        double start_board;
        double result;
        while (1)
          {
            fprintf (stdout, "Input [eps]: ");
            if (fscanf (stdin, "%lf", &eps) != 1)
              {
                fprintf (stdout, "Cannot read [eps]!\n");
                return 1;
              }
            if (eps < 0)
              {
                return 0;
              }
            fprintf (stdout, "Input [x0]: ");
            if (fscanf (stdin, "%lf", &start_board) != 1)
              {
                fprintf (stdout, "Cannot read [x0]!\n");
                return 1;
              }

            counter_of_time = clock ();
            result = calculate_integral8 (f, start_board, eps, &answer);
            counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;

            if (result < 0)
              {
                fprintf (stdout, "Cannot solve!\n");
                continue;
              }
            fprintf (stdout, "Integral = %.10f\n", answer);
            fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);
          }
        break;
      }


    case 9:
      {
        double (*x) (double), (*y) (double);
        double eps = 1;
        double left_board, right_board;
        int result;

	x = &coordinate_x;
	y = &coordinate_y;
	while (1)
	  {
	    fprintf (stdout, "Input [eps]: ");
	    if (fscanf (stdin, "%lf", &eps) != 1)
	      {
		fprintf (stdout, "Cannot read [eps]!\n");
		return 1;
	      }
	    if (eps < 0)
	      {
		return 0;
	      }
	    fprintf (stdout, "Input [a]: ");
	    if (fscanf (stdin, "%lf", &left_board) != 1)
	      {
		fprintf (stdout, "Cannot read [a]!\n");
		return 1;
	      }
	    fprintf (stdout, "Input [b]: ");
	    if (fscanf (stdin, "%lf", &right_board) != 1)
	      {
		fprintf (stdout, "Cannot read [b]!\n");
		return 1;
	      }


            counter_of_time = clock ();
            result = calculate_length9 (x, y, left_board, right_board, eps, &answer);
            counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;

            if (result < 0)
              {
                fprintf (stdout, "Cannot solve!\n");
                continue;
              }
            fprintf (stdout, "Length = %.10f\n", answer);
            fprintf (stdout, "Iteratios = %d\n", result);
            fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);
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
