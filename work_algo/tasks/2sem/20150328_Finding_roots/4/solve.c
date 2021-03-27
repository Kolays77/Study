#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

#define MAX_ITERATION 100000
#define EPS 0.0000000000000001

double function(double x)
{
	return x * x -2 * x -159;
}

int find_root(double left_board,
              double right_board,
              double (*f)(double),
              double eps,
              double *answer)
{
	int count_iter;
	double new = left_board, f_NEW,
	f_LEFT = f(left_board), f_RIGHT = f(right_board);
	(void) answer;
	for (count_iter = 0; count_iter < MAX_ITERATION; count_iter++)
	{
		if (fabs(right_board - left_board) < eps)
		{
			break;
		}
		if (fabs(f_LEFT - f_RIGHT) < eps)
		{
			return -1;
		}
		new = right_board + f_RIGHT * (right_board - left_board) / (f_LEFT - f_RIGHT);
		f_NEW = f(new);
		if (f_LEFT < f_RIGHT)
		{
			if (f_LEFT < f_NEW)
			{
				return -1;
			}
			else
			{
				right_board = left_board;
				f_RIGHT = f_LEFT;
				left_board = new;
				f_LEFT = f_NEW;
			}
		}
		else
		{
			if (f_RIGHT < f_NEW)
			{
				return -1;
			}
			else
			{
				left_board = right_board;
				f_LEFT = f_RIGHT;
				right_board = new;
				f_RIGHT = f_NEW;
			}
		}
	}
	*answer = new;
	return count_iter;
}
