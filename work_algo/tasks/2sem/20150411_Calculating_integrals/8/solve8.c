#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

#define MAX_N 1e8

double function(double x)
{
    return x * x;
}

void calculate_integral(double (*f)(double),
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
    printf("Answer: %.10f\n\n", s_current);
    return;
}
