#include "head.h"
#include "read.h"

int main (int argc, char *argv[])
{
  char *name = 0;
  int n = 0, result, task_number = 0;
  double *x = 0, *y = 0, x0;
  double counter_of_time, answer;

  if (argc < 2 || (task_number = atoi(argv[1])) <= 0)
    {
      fprintf (stdout, "Cannot read [#]!\n");
      return 1;
    }


  if (task_number <= 4)
    {
      if (argc != 4)
        {
          fprintf (stdout, "Usage: %s [#] [n] [<file>]\n", argv[0]);
          return 1;
        }
      if ((n = atoi(argv[2])) <= 0)
        {
          fprintf (stdout, "Cannot read [n]!\n");
          return 1;
        }

      name = argv[3];
      fprintf (stdout, "input [x0]: ");
      if (fscanf (stdin, "%lf", &x0) != 1)
        {
          fprintf (stdout, "Cannot read [x0]!\n");
          return 1;
        }
      x = new double [n];
      y = new double [n];
    }
  else
    {
      if (argc != 2)
        {
          fprintf (stdout, "Usage: %s [#]\n", argv[0]);
          return 1;
        }
    }

  switch (task_number)
    {
    case 1:
      {
        result = read (name, x, y, n);
        if (result < 0)
          {
            return_error (result, name);
            delete [] x;
            delete [] y;
            return 3;
          }

        print_function (x, y, n);
        counter_of_time = clock ();
        answer = interpolation_lagrange (x, y, n, x0);
        counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;
        fprintf (stdout, "ANSWER: %.3f\n", answer);
        fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);
        delete [] x;
        delete [] y;
        break;
      }

    case 2:
      {
        result = read (name, x, y, n);
        if (result < 0)
          {
            return_error (result, name);
            delete [] x;
            delete [] y;
            return 3;
          }

        counter_of_time = clock ();
        print_function (x, y, n);
        if (!make_function (x, y, n))
          {
            delete [] x;
            delete [] y;
            return 0;
          }
        answer = interpolation_newton (x, y, n, x0);
        counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;
        fprintf (stdout, "ANSWER: %.3f\n", answer);
        fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);
        delete [] x;
        delete [] y;
        break;
      }

    case 3:
      {
        result = read (name, x, y, n);
        if (result < 0)
          {
            return_error (result, name);
            delete [] x;
            delete [] y;
            return 3;
          }

        print_function (x, y, n);
        counter_of_time = clock ();
        if (!interpolation_eitken (x, y, n, x0))
          {
            delete [] x;
            delete [] y;
            return 0;
          }
        counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;
        fprintf (stdout, "ANSWER: %.3f\n", y[n - 1]);
        fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);
        delete [] x;
        delete [] y;
        break;
      }

    case 4:
      {
        double *dif;
        dif = new double [n];
        result = read (name, x, y, dif, n);
        if (result < 0)
          {
            return_error (result, name);
            delete [] x;
            delete [] y;
            delete [] dif;
            return 3;
          }

        print_function (x, y, n);
        counter_of_time = clock ();
        if (!interpolation_eitken (x, y, n, x0))
          {
            delete [] x;
            delete [] y;
            delete [] dif;
            return 0;
          }
        counter_of_time = (clock () - counter_of_time) / CLOCKS_PER_SEC;
        fprintf (stdout, "ANSWER: %.3f\n", y[n - 1]);
        fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);
        delete [] dif;
        delete [] x;
        delete [] y;
        break;
      }

    case 5:
      {

        double x, sin_x, eps = 1;

        while (eps > 0)
          {
            fprintf (stdout, "Input [x]: ");
            if (fscanf (stdin, "%lf", &x) != 1)
              {
                fprintf (stdout, "Cannot read [x]!\n");
                return 1;
              }
            fprintf (stdout, "Input [eps]: ");
            if (fscanf (stdin, "%lf", &eps) != 1)
              {
                fprintf (stdout, "Cannot read [eps]!\n");
                return 1;
              }
            if (eps <= 0)
              {
                break;
              }
            sin_x = get_sin (x, eps);
            fprintf (stdout, "sin(x) = %.3f; eps = %e\n\n", sin_x, fabs (sin_x - sin (x)));
          }
        break;
      }

    case 6:
      {
        double x, cos_x, eps = 1;

        while (eps > 0)
          {
            fprintf (stdout, "Input [x]: ");
            if (fscanf (stdin, "%lf", &x) != 1)
              {
                fprintf (stdout, "Cannot read [x]!\n");
                return 1;
              }
            fprintf (stdout, "Input [eps]: ");
            if (fscanf (stdin, "%lf", &eps) != 1)
              {
                fprintf (stdout, "Cannot read [eps]!\n");
                return 1;
              }
            if (eps <= 0)
              {
                break;
              }
            cos_x = get_cos (x, eps);
            fprintf (stdout, "sin(x) = %.3f; eps = %e\n\n", cos_x, fabs (cos_x - cos (x)));
          }
        break;
      }

    case 7:
      {
        double x, exp_x, eps = 1;

        while (eps > 0)
          {
            fprintf (stdout, "Input [x]: ");
            if (fscanf (stdin, "%lf", &x) != 1)
              {
                fprintf (stdout, "Cannot read [x]!\n");
                return 1;
              }
            fprintf (stdout, "Input [eps]: ");
            if (fscanf (stdin, "%lf", &eps) != 1)
              {
                fprintf (stdout, "Cannot read [eps]!\n");
                return 1;
              }
            if (eps <= 0)
              {
                break;
              }
            exp_x = get_exp (x, eps);
            fprintf (stdout, "exp(x) = %.3f; eps = %e\n\n", exp_x, fabs (exp_x - exp (x)));
          }
        break;
      }

    case 8:
      {
        double x, log_x, eps = 1;

        while (eps > 0)
          {
            fprintf (stdout, "Input [x]: ");
            if (fscanf (stdin, "%lf", &x) != 1)
              {
                fprintf (stdout, "Cannot read [x]!\n");
                return 1;
              }
            if (x <= 0)
              {
                break;
              }
            fprintf (stdout, "Input [eps]: ");
            if (fscanf (stdin, "%lf", &eps) != 1)
              {
                fprintf (stdout, "Cannot read [eps]!\n");
                return 1;
              }
            if (eps <= 0)
              {
                break;
              }
            log_x = get_log (x, eps);
            fprintf (stdout, "log(x) = %.3f; eps = %e\n\n", log_x, fabs (log_x - log(x)));
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
