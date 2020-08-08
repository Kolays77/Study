#include "head.h"

double function (double x)
{
  (void) x;
  return 4 - x * x;
}


double differential (double x)
{
  (void) x;
  return 0;
}



int find_root1 (double (*f) (double),
                double left_board,
                double right_board,
                double eps,
                double *answer)
{
  double middle = 0, f_middle = 0, f_left_board = f (left_board), f_right_board = f (right_board);

  if (f_left_board * f_right_board > 0)
    {
      return -1;
    }

  if (fabs (f_left_board) < eps)
    {
      *answer = left_board;
      return 0;
    }
  if (fabs (f_right_board) < eps)
    {
      *answer = right_board;
      return 0;
    }
  for (int count_iterations = 0; count_iterations < MAX_NUM_ITERATIONS; count_iterations++)
    {
      middle = (right_board - left_board) / 2 + left_board;
      f_middle = f (middle);
      if (right_board - left_board < eps)
        {
          *answer = middle;
          return count_iterations;
        }
      if (f_left_board * f_right_board < 0)
        {
          if (f_middle * f_left_board < 0)
            {
              right_board = middle;
              f_right_board = f_middle;
            }
          else
            {
              left_board = middle;
              f_left_board = f_middle;
            }
        }

    }
  *answer = middle;
  return MAX_NUM_ITERATIONS;
}


int find_root2 (double (*f) (double),
                double (*dif) (double),
                double x_start,
                double eps,
                double *answer)
{
  double cur_f = f (x_start),
      cur_dif = dif (x_start),
      cur_x = x_start;

  for (int count_iterations = 0; count_iterations < MAX_NUM_ITERATIONS; count_iterations++)
    {
      if (fabs (cur_dif) < eps)
        {
          return -1;
        }
      if (fabs (cur_f) < eps)
        {
          *answer = cur_x;
          return count_iterations;
        }
      cur_x -= cur_f / cur_dif;
      cur_f = f (cur_x);
      cur_dif = dif (cur_x);
    }
  *answer = cur_x;
  return MAX_NUM_ITERATIONS;
}

int find_root3 (double (*f) (double),
                double left_board,
                double right_board,
                double eps,
                double *answer)
{
  double new_point = left_board, previous = right_board,
      f_left_board = f (left_board),
      f_right_board = f (right_board),
      f_new = f (new_point);

  for (int count_iterations = 0; count_iterations < MAX_NUM_ITERATIONS; count_iterations++)
    {
      if (fabs (f_left_board) < eps)
        {
          *answer = left_board;
          return count_iterations;
        }
      else if (fabs (f_right_board) < eps)
        {
          *answer = right_board;
          return count_iterations;
        }
      if (fabs (f_left_board - f_right_board) < eps)
        {
          return -1;
        }
      new_point = right_board - f_right_board * (right_board - left_board) / (f_right_board - f_left_board);
      f_new = f (new_point);
      if (f_new * f_left_board < 0)
        {
          if (fabs (new_point - right_board) < eps)
            {
              *answer = right_board;
              return count_iterations;
            }
          previous = right_board;
          right_board = new_point;
          f_right_board = f_new;
        }
      else
        {
          if (fabs (new_point - left_board) < EPS)
            {
              *answer = left_board;
              return count_iterations;
            }
          previous = left_board;
          left_board = new_point;
          f_left_board = f_new;
        }
    }
  *answer = previous;
  return MAX_NUM_ITERATIONS;
}

int find_root4 (double (*f) (double),
                double left_board,
                double right_board,
                double eps,
                double *answer)
{
  double new_point = left_board,
      f_left_board = f (left_board),
      f_right_board = f (right_board),
      f_new = f (new_point);

  for (int count_iterations = 0; count_iterations < MAX_NUM_ITERATIONS; count_iterations++)
    {
      if (fabs (right_board - left_board) < eps)
        {
          *answer = new_point;
          return count_iterations;
        }
      if (fabs (f_left_board) < eps)
        {
          *answer = left_board;
          return count_iterations;
        }
      if (fabs (f_right_board) < eps)
        {
          *answer = right_board;
          return count_iterations;
        }

      if (fabs (f_left_board - f_right_board) < EPS)
        {
          return -1;
        }
      new_point = left_board - f_left_board * (right_board - left_board) / (f_right_board - f_left_board);
      f_new = f (new_point);
      if (fabs (f_left_board) < fabs (f_right_board))
        {
          right_board = left_board;
          f_right_board = f_left_board;
          left_board = new_point;
          f_left_board = f_new;
        }
      else
        {
          left_board = right_board;
          f_left_board = f_right_board;
          right_board = new_point;
          f_right_board = f_new;
        }
    }
  *answer = new_point;
  return MAX_NUM_ITERATIONS;
}

int find_root5 (double (*f) (double),
                double x0,
                double x2,
                double x1,
                double eps,
                double *answer)
{
  double y0 = f (x0),
      y1 = f (x1),
      y2 = f (x2),
      y3 = 0,
      f2_01, f2_12, f3_012, x3 = 0;

  for (int count_iterations = 0; count_iterations < MAX_NUM_ITERATIONS; count_iterations++)
    {
      if (fabs (y1 - y0) < EPS || fabs (y2 - y0) < EPS || fabs (y1 - y2) < EPS)
        {
          return -1;
        }
      f2_01 = (x1 - x0) / (y1 - y0);
      f2_12 = (x2 - x1) / (y2 - y1);
      f3_012 = (f2_12 - f2_01) / (y2 - y0);
      x3 = x0 - y0 * f2_01 + y0 * f3_012 * y1;
      y3 = f (x3);
      if (fabs (y3) < eps)
        {
          *answer = x3;
          return count_iterations;
        }
      if (y3 >= y0 && y3 >= y1 && y3 >= y2)
        {
          return -1;
        }
      if (y2 > y0 && y2 > y1)
        {
          x2 = x3;
          y2 = y3;
          continue;
        }
      if (y1 > y0)
        {
          x1 = x3;
          y1 = y3;
        }
      else
        {
          x0 = x3;
          y0 = y3;
        }

    }
  *answer = x3;
  return MAX_NUM_ITERATIONS;
}


int make_dif (double *x, double *y, double *f, int n)
{
  for (int i = 0; i < n; i++)
    {
      f[i] = y[i];
    }
  for (int counter = 1; counter < n; counter++)
    {
      for (int i = n - 1, j = i - counter; i >= counter; i--, j--)
        {
          if (fabs (x[i] - x[j]) < EPS)
            {
              fprintf (stdout, "Error data: x[%d] = x[%d]\n", j, i);
              return -1;
            }
          f[i] = (f[i] * (-x[j]) + f[i - 1] * (x[i])) / (x[i] - x[j]);
        }
    }
  return 0;
}

int find_root6 (double (*f)(double),
                double *dif,
                double left_board,
                double right_board,
                int deg,
                double eps,
                double *answer)
{
  int max_idx;
  double y_new, y_max;
  double *pointer_x = dif + deg + 1, *pointer_f = dif + 2 * deg + 1;
  double h = (right_board - left_board) / (deg - 1);

  dif[0] = left_board;
  dif[deg + 1] = dif[2 * deg + 1] = f (dif[0]);

  for (int idx = 1; idx < deg; idx++)
    {
      dif[idx] = dif[idx - 1] + h;
      pointer_f[idx] = pointer_x[idx] = f (dif[idx]);
    }

  for (int count_iterations = 0; count_iterations < MAX_NUM_ITERATIONS; count_iterations++)
    {
      int result = make_dif (pointer_x, dif, pointer_f, deg);
      if (result != 0)
        {
          return -1;
        }
      dif[deg] = dif[3 * deg];
      max_idx = deg;
      y_max = y_new = f (dif[deg]);
      if (fabs (y_new) < eps)
        {
          *answer = dif[deg];
          return count_iterations;
        }
      for (int idx = deg + 1; idx <= 2 * deg; idx++)
        {
          if (fabs (dif[idx]) > y_max)
            {
              y_max = fabs (dif[idx]);
              max_idx = idx - deg - 1;
            }
        }
      if (deg == max_idx)
        {
          return -1;
        }
      dif[max_idx] = dif[deg];
      dif[max_idx + deg + 1] = y_new;
    }
  *answer = dif[deg];
  return MAX_NUM_ITERATIONS;
}

int find_root7 (double (*f) (double),
                double (*dif) (double),
                double x_start,
                double eps,
                double *x)
{
  if (fabs (dif (x_start)) >= 1)
    {
      return -2;
    }

  for (int count_iterations = 0; count_iterations < MAX_NUM_ITERATIONS; count_iterations++)
    {
      *x = f (x_start);
      if (fabs (*x - x_start) < eps)
        {
          *x = x_start;
          return count_iterations;
        }
      x_start = *x;
    }
  *x = f (x_start);
  return -1;
}


int find_max8 (double (*f) (double),
               double left_board,
               double right_board,
               double eps,
               double *answer)
{
  double h = (right_board - left_board) / NUMBER_OF_STEPS;
  double current_x = left_board;
  double previous_x = current_x, previous_f = f (previous_x), previous2_f = f (previous_x);
  double current_f = f(current_x);

  current_x += h;

  for (int count_iterations = 0; count_iterations < MAX_NUM_ITERATIONS; count_iterations++)
    {
      if (current_x > right_board || current_x < left_board)
        {
          current_x -= h;
          if (fabs (h) < eps)
            {
              *answer = previous_x;
              return count_iterations;
            }
          h /= NUMBER_OF_STEPS;
          current_x += h;
          current_f = f (current_x);
          continue;
        }
      if (current_f < previous_f && previous_f >= previous2_f)
        {
          if (fabs (h) < eps)
            {
              *answer = previous_x;
              return count_iterations;
            }
          h /= (-NUMBER_OF_STEPS);
          previous2_f = previous_f;
          previous_x = current_x;
          current_x += h;
          previous_f = current_f;
          continue;
        }
      previous_x = current_x;
      current_x += h;
      previous2_f = previous_f;
      previous_f = current_f;
      current_f = f (current_x);

      if (fabs (h) < eps)
        {
          *answer = previous_x;
          return count_iterations;
        }
    }
  return -1;
}

int find_max9 (double (*f) (double),
               double left_board,
               double right_board,
               double eps,
               double *answer)
{
  double GOLDEN_SECTION = (3 + sqrt(5)) / 2;
  double x_left, x_right, h, f_left, f_right;

  h = (right_board - left_board) / GOLDEN_SECTION;
  x_left = left_board + h;
  x_right = right_board - h;
  f_left = f (x_left);
  f_right = f (x_right);

  for (int count_iterations = 0; count_iterations < MAX_NUM_ITERATIONS; count_iterations++)
    {
      if (fabs (right_board - left_board) < eps)
        {
          *answer = (right_board + left_board) / 2;
          return count_iterations;
        }
      if (f_left <= f_right)
        {
          left_board = x_left;
          x_left = x_right;
          f_left = f_right;
          x_right = right_board - (right_board - left_board) / GOLDEN_SECTION;
          f_right = f (x_right);
        }
      else
        {
          right_board = x_right;
          x_right = x_left;
          f_right = f_left;
          x_left = left_board + (right_board - left_board) / GOLDEN_SECTION;
          f_left = f (x_left);
        }
    }
  return -1;
}

int find_max10 (double (*f) (double),
                double x0,
                double x2,
                double x1,
                double eps,
                double *answer)
{
  double f0 = f(x0), f1 = f(x1), f2 = f(x2), f3 = 1,
      f2_01, f2_12, f3_012,
      x3 = x1;
  double coeff_a, coeff_b;
  double left_board = x0, right_board = x2;
  for (int count_iterations = 0; count_iterations < MAX_NUM_ITERATIONS; count_iterations++)
    {
      if (fabs (x1 - x0) < eps)
        {
          *answer = x1;
          return count_iterations;
        }
      if (fabs (x2 - x0) < eps)
        {
          *answer = x2;
          return count_iterations;
        }
      if (fabs (x1 - x2) < eps)
        {
          *answer = x1;
          return count_iterations;
        }
      f2_01 = (f1 - f0) / (x1 - x0);
      f2_12 = (f2 - f1) / (x2 - x1);
      f3_012 = (f2_12 - f2_01) / (x2 - x0);
      coeff_a = f3_012;
      coeff_b = f2_01 - (x0 + x1) * f3_012;
      if (fabs (coeff_a) < EPS)
        {
          if (coeff_b > 0)
            {
              *answer = right_board;
            }
          else if (coeff_b < 0)
            {
              *answer = left_board;
            }
          else
            {
              *answer = x3;
            }
          return count_iterations;
        }
      if (x3 < left_board || x3 > right_board)
        {
          return -1;
        }
      x3 = -coeff_b / (2 * coeff_a);
      f3 = f (x3);

      if (f3 <= f0 && f3 <= f1 && f3 <= f2)
        {
          return -1;
        }
      if (f2 < f0 && f2 < f1)
        {
          x2 = x3;
          f2 = f3;
        }
      else if (f1 < f0)
        {
          x1 = x3;
          f1 = f3;
        }
      else
        {
          x0 = x3;
          f0 = f3;
        }

    }
  *answer = x3;
  return MAX_NUM_ITERATIONS;
}
