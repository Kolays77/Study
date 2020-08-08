#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

#define MAX_N 10000000
#define MAX_ITERATIONS 10000
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
  double h = (b - a);
  double s_current = 0, s_previous, sum = 0;
  long long idx, n = 1;
  s_current = (f(a) + f(b)) / 2;
  s_current *= h;
  s_previous = s_current + (1 + eps);
  while (fabs(s_current - s_previous) > eps && n < MAX_N)
    {
      s_previous = s_current;
      sum = 0;
      h /= 2;
      for (idx = 1; idx <= n; idx++)
        {
          sum += f(a + (2 * idx - 1) * h);
        }
      n *= 2;
      sum *= h;
      s_current /= 2;
      s_current += sum;
    }
  return s_current;
}

double calculate_integral(double (*f)(double),
			  double a,
			  double *result,
			  double eps)
{
  double h = 1, b;
  double current_integral = 0;
  int count_iter = 0;
  (void) eps;
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
