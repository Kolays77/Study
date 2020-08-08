#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

#define MAX_ITERATIONS 10000
#define MAX_N 100000
#define EPS 0.000001

double function(double x)
{
  return 1 / (x * x);
}

double calculate_current_integral(double (*f)(double),
				  double a,
				  double b,
				  double eps)
{	
  long long n = 1;
  double h = (b - a) / (2 * n);
  double sum = 0, s_cur1 = 0, s_cur2 = 0, s_prev, answer = 0;
  long long idx;

  sum = (f(a) + function(b)) * h / 3;
  s_cur2 += function(a + h);
  answer = sum + (2 * s_cur1 + 4 * s_cur2) * h / 3;
  s_prev = answer - (1 + eps);
  while (fabs(answer - s_prev) > eps && n < MAX_N)
    {
      s_prev = answer;
      s_cur1 = (s_cur1 + s_cur2);
      s_cur2 = 0;
      sum /= 2;
      n *= 2;
      h /= 2;
      for (idx = 0; idx < n; idx++)
        {
          s_cur2 += f(a + (2 * idx + 1) * h);
        }
      answer = sum + (2 * s_cur1 + 4 * s_cur2) * h / 3;
    }
  return answer;
}

double calculate_integral(double (*f)(double),
			  double a,
			  double *result,
			  double eps)
{
  double h = 1, b;
  double current_integral = 0;
  int count_iter = 0;
  *result = 0;
  for (count_iter = 0; count_iter < MAX_ITERATIONS; count_iter++)
    {
      b = a + h;
      current_integral = calculate_current_integral(f, a, b, eps);
      *result += current_integral;
      if (fabs(current_integral) < eps)
        {
          return b;
        }
      a = b;
      h *= 2;
    }
  return -1;
}
