#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

#define MAX_ITERATION 100000
#define EPS 0.0000000000000001
#define DIV 10

double function(double x)
{
	return 2*x/(x * x + 1);
}

int find_max(double left_board,
			  double right_board,
              double (*f)(double),
              double eps,
              double *x)
{
	int count_iter;
	(void) x;
	double GOLDEN_SECTION = (3 + sqrt(5)) / 2;
	double x1, x2, h, f1, f2;
	
	for (count_iter = 0; count_iter < MAX_ITERATION; count_iter++)
	{
		if (fabs(right_board - left_board) < eps)
		{
			*x = (right_board + left_board) / 2;
			return count_iter;
		}
		h = (right_board - left_board) / GOLDEN_SECTION;
		x1 = left_board + h;
		x2 = right_board - h;
		f1 = f(x1);
		f2 = f(x2);
		if (f1 <= f2)
		{
			left_board = x1;
		}
		else
		{
			right_board = x2;
		}
	}
	return -1;
}
