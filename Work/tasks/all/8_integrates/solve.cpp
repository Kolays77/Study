#include "head.h"

double function (double x)
{
  return 1 / (x*x + 1);
}

double calculate_integral1 (double (*f) (double),
			    double left_board,
			    double right_board,
			    int n)
{
  double h = (right_board - left_board) / n;
  double x = left_board, sum = 0;
  sum = (f (left_board) + f (right_board)) / 2;
  for (int idx = 1; idx < n; idx++)
    {
      sum += f (x + h * idx);
    }
  sum *= h;
  return sum;
}

double calculate_integral2 (double (*f)(double),
			    double left_board,
			    double right_board,
			    int n)
{
  double h = (right_board - left_board) / (2 * n);
  double x = left_board, sum = 0;
  sum = (f (left_board) + f (right_board)) / 2;
  for (int idx = 1; idx < 2 * n; idx++)
    {
      if (idx % 2 == 1)
        {
          sum += 2 * f (x + idx * h);
        }
      else
        {
          sum += f (x + idx * h);
        }
    }
  sum *= (2 * h / 3);
  return sum;
}


int sign (double x)
{
  return (x > 0) - (x < 0);
}

double calculate_integral3 (double (*f)(double),
			    double left_board,
			    double right_board,
			    int n)
{
  double h = (right_board - left_board) / n;
  double x = left_board, x_next,
      f_x = f (x),
      f_x_next, difference, sum = 0;

  for (int idx = 0; idx < n; idx++)
    {
      x_next = x + h;
      f_x_next = f (x_next);
      difference = (f_x_next - f_x) / h;
      sum += 2 * (f_x - difference * x) *
          (sqrt (fabs (x_next)) * sign (x_next) - sqrt (fabs(x)) * sign (x));
      sum += 2.0 / 3 * difference * (fabs (x_next) * sqrt (fabs (x_next)) - fabs(x) * sqrt (fabs (x)));
      x = x_next;
      f_x = f_x_next;
    }
  return sum;
}


double calculate_integral4 (double (*f) (double),
			    double left_board,
			    double right_board,
			    int n)
{
  double h = (right_board - left_board) / (2 * n);
  double x = left_board,
      x_middle, x_next,
      f_x = f(x), f_x_middle, f_x_next,
      difference12, difference23, difference123,
      sum = 0;

  for (int idx = 0; idx < n; idx++)
    {
      x_middle = x + h;
      x_next = x + 2 * h;
      f_x_middle = f(x_middle);
      f_x_next = f(x_next);
      difference12 = (f_x_middle - f_x) / h;
      difference23 = (f_x_next - f_x_middle) / h;
      difference123 = (difference23 - difference12) / (2 * h);
      sum += 2 * (f_x - x * difference12 + x * x_middle * difference123) *
          (sqrt(fabs(x_next)) * sign(x_next) - sqrt(fabs(x)) * sign(x));
      sum += 2.0 / 3 * (difference12 - (x + x_middle) * difference123) *
          (x_next * sqrt(fabs(x_next)) * sign(x_next) - x * sqrt(fabs(x)) * sign(x));
      sum += 2.0 / 5 * difference123 *
          (x_next * x_next * sqrt(fabs(x_next)) * sign(x_next) - x * x * sqrt(fabs(x)) * sign(x));
      x = x_next;
      f_x = f_x_next;
    }
  return sum;
}


int calculate_integral5 (double (*f) (double),
			 double left_board,
			 double right_board,
			 double eps,
			 double *answer)
{
  double h = (right_board - left_board);
  double s_current = 0, s_previous, sum = 0;
  int count_iterations = 1;
  s_current = (f (left_board) + f (right_board)) / 2;
  s_current *= h;
  s_previous = s_current + (1 + eps);
  while (fabs (s_current - s_previous) > eps && count_iterations < MAX_NUM_ITERATIONS)
    {
      s_previous = s_current;
      sum = 0;
      h /= 2;
      for (int idx = 1; idx <= count_iterations; idx++)
        {
          sum += f (left_board + (2 * idx - 1) * h);
        }
      count_iterations *= 2;
      sum *= h;
      s_current /= 2;
      s_current += sum;
    }
  if (count_iterations < MAX_NUM_ITERATIONS)
    {
      *answer = s_current;
      return count_iterations;
    }
  return -1;
}

int calculate_integral6 (double (*f) (double),
			 double left_board,
			 double right_board,
			 double eps,
			 double *answer)
{

  int count_iterations = 1;
  double h = (right_board - left_board) / 2;
  double sum = 0,
      s_cur1 = 0,
      s_cur2 = 0,
      s_prev,
      result = 0;

  sum = (f (left_board) + f (right_board)) * h / 3;
  s_cur2 += f (left_board + h);
  result = sum + (2 * s_cur1 + 4 * s_cur2) * h / 3;
  s_prev = result - (1 + eps);
  while (fabs (result - s_prev) > eps && count_iterations < MAX_NUM_ITERATIONS)
    {
      s_prev = result;
      s_cur1 = (s_cur1 + s_cur2);
      s_cur2 = 0;
      sum /= 2;
      count_iterations *= 2;
      h /= 2;
      for (int idx = 0; idx < count_iterations; idx++)
        {
          s_cur2 += f (left_board + (2 * idx + 1) * h);
        }
      result = sum + (2 * s_cur1 + 4 * s_cur2) * h / 3;
    }
  if (count_iterations < MAX_NUM_ITERATIONS)
    {
      *answer = result;
      return count_iterations;
    }
  return -1;
}

double calculate_integral7 (double (*f)(double),
			    double start,
			    double eps,
			    double *answer)
{
  double h = 1, right_board;
  double current_integral = 0;
  double result = 0;
  for (int count_iterations = 0; count_iterations < MAX_NUM_ITERATIONS_INF; count_iterations++)
    {
      right_board = start + h;
      if (calculate_integral5 (f, start, right_board, eps, &current_integral) < 0)
        {
          return -1;
        }
      result += current_integral;
      if (fabs (current_integral) < eps)
        {
          *answer = result;
          return right_board;
        }
      start = right_board;
      h *= 2;
    }
  return -1;
}

double calculate_integral8 (double (*f)(double),
			    double start,
			    double eps,
			    double *answer)
{
  double h = 1, right_board;
  double current_integral = 0;
  double result = 0;
  for (int count_iterations = 0; count_iterations < MAX_NUM_ITERATIONS_INF; count_iterations++)
    {
      right_board = start + h;
      if (calculate_integral6 (f, start, right_board, eps, &current_integral) < 0)
        {
          return -1;
        }
      result += current_integral;
      if (fabs (current_integral) < eps)
        {
          *answer = result;
          return right_board;
        }
      start = right_board;
      h *= 2;
    }
  return -1;
}


double coordinate_x (double t)
{
  return t;
}

double coordinate_y (double t)
{
  return t;
}

int calculate_length9 (double (*x) (double),
		       double (*y) (double),
		       double left_board,
		       double right_board,
		       double eps,
		       double *answer)
{
  int count_iterations = 1;
  double h, t,
      x_cur, y_cur,
      x_next, y_next,
      x_start = x (left_board), y_start = y(left_board);
  double s_prev = -eps - 1;
  double result = 0;

  while (count_iterations < MAX_NUM_ITERATIONS)
    {
      s_prev = result;
      result = 0;
      h = (right_board - left_board) / count_iterations;
      x_cur = x_start; y_cur = y_start;
      t = left_board;
      for (int idx = 1; idx <= count_iterations; idx++)
        {
          x_next = x (t + idx * h);
          y_next = y (t + (idx + 1) *h);
          result += sqrt ((y_next - y_cur) * (y_next - y_cur) + (x_next - x_cur) * (x_next - x_cur));
          x_cur = x_next;
          y_cur = y_next;
        }
      if (fabs (s_prev - result) < eps)
        {
          *answer = result;
          return count_iterations;
        }
      x_cur = x_next;
      y_cur = y_next;
      count_iterations *= 2;
    }
  return -1;
}
