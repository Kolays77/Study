#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

#define MAX_ITERATION 100000
#define EPS 0.0000000000000001

double function(double x)
{
	return x*x - 2*x - 159;
}

int find_root(double (*f)(double),
              double left_board,
              double right_board,
              double eps,
              double *answer)
{
	int count_iter;
	double middle = 0, f_MIDDLE,
	f_LEFT = f(left_board);
	(void) answer;
	for (count_iter = 0; count_iter < MAX_ITERATION; count_iter++)
	{
		if (right_board - left_board < eps)
		{
			break;
		}
		middle = (right_board - left_board) / 2 + left_board;
		//printf("%.3f\n", middle);
		if (fabs(middle - right_board) < EPS)
		{
			answer = &right_board;
			return count_iter;
		}
		if (fabs(middle - left_board) < EPS)
		{
			answer = &left_board;
			return count_iter;
		}
	
		f_MIDDLE = f(middle);
		if (f_MIDDLE * f_LEFT < 0)
		{
			right_board = middle;
		}
		else
		{
			left_board = middle;
			f_LEFT = f_MIDDLE;
		}
	}
	*answer = middle;
	return count_iter;
}
