#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

#define MAX_ITERATION 100
#define EPS 0.0000000000000001

double function(double x)
{
	return log(x);
}

int find_max(double x0,
              double x2,
              double x1,
              double (*f)(double),
              double eps,
              double *answer)
{
	int count_iter;
	double y0 = f(x0), y1 = f(x1), y2 = f(x2), y3 = 1, f_01, f_12, f_012, x3 = x1;
	double parabA, parabB;
	(void) answer;
	double left_board = x0, right_board = x2;
	for (count_iter = 0; count_iter < MAX_ITERATION; count_iter++)
	{
		if (fabs(x1 - x0) < eps)
		{
			*answer = x1;
			return count_iter;
		}
		if (fabs(x2 - x0) < eps)
		{
			*answer = x2;
			return count_iter;
		}
		if (fabs(x1 - x2) < eps)
		{
			*answer = x1;
			return count_iter;
		} 
		f_01 = (y1 - y0) / (x1 - x0);
		f_12 = (y2 - y1) / (x2 - x1);
		f_012 = (f_12 - f_01) / (x2 - x0);
		parabA = f_012;
		parabB = f_01 - (x0 + x1) * f_012;
		if (fabs(parabA) < EPS)
		{
			if (fabs(parabB) < EPS)
			{
				*answer = x3;
				return count_iter;
			}
			if (parabB > 0)
			{
				*answer = right_board;
			}
			else
			{
				*answer = left_board;
			}
			return count_iter;
		}
		if (x3 < left_board || x3 > right_board)
		{
			return -1;
		}
		x3 = -parabB / (2 * parabA);
		y3 = f(x3);
		
		if (y3 <= y0 && y3 <= y1 && y3 <= y2)
		{
			return -1;
		}
		if (y2 < y0 && y2 < y1)
		{
			x2 = x3;
			y2 = y3;
			continue;
		}
		if (y1 < y0)
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
	return count_iter;
}
