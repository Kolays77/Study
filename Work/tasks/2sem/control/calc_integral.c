#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

#define MAX_N 10000000

double calculate_integral(double x,
			  double a,
			  double b,
			  double eps)
{
    long long n = 1, idx;
    double h = (b - a) / (2 * n);
    double sum = 0, s_cur1 = 0, s_cur2 = 0, s_prev, answer = 0;

    sum = (function(x, a) + function(x, b)) * h / 3;
    s_cur2 += function(x, a + h);
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
            s_cur2 += function(x, a + (2 * idx + 1) * h);
          }
        answer = sum + (2 * s_cur1 + 4 * s_cur2) * h / 3;
      }
    return answer;
}
