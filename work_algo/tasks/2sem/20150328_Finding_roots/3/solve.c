#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

#define MAX_ITERATION 100000
#define EPS 0.0000000000000001

double function(double x)
{
	return sin(x);
}

int find_root(double left_board,
              double right_board,
              double (*f)(double),
              double eps,
              double *answer)
{
	int count_iter;
	double new = left_board, f_NEW, previous = right_board,
	f_LEFT = f(left_board), f_RIGHT = f(right_board);
	(void) answer;
	for (count_iter = 0; count_iter < MAX_ITERATION; count_iter++)
	{
		if (fabs(f_LEFT - f_RIGHT) < eps)
		{
			return -1;
		}
		new = right_board + f_RIGHT * (right_board - left_board) / (f_LEFT - f_RIGHT);
		f_NEW = f(new);
		if (f_NEW * f_LEFT < 0)
		{
			if (fabs(new - right_board) < eps)
			{
				*answer = right_board;
				return count_iter;
			}
			previous = right_board;
			right_board = new;
			f_RIGHT = f_NEW;
		}
		else
		{
			if (fabs(new - left_board) < EPS)
			{
				*answer = left_board;
				return count_iter;
			}
			previous = left_board;
			left_board = new;
			f_LEFT = f_NEW;
		}
	}
	*answer = previous;
	return count_iter;
}
