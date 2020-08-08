#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

#define MAX_ITERATION 100000
#define EPS 0.0000000000000001
#define DIV 10

double function(double x)
{
	return 1 - 1 / x;
}

int find_max(double left_board,
			  double right_board,
              double (*f)(double),
              double eps,
              double *x)
{
	int count_iter;
	(void) x;
	double h = (right_board - left_board) / DIV, current_x = left_board;
	double previous_x = current_x, previous_f = f(previous_x), previous_2f = previous_f + 1;
	current_x += h;
	double current_f = f(current_x);
	
	for (count_iter = 0; count_iter < MAX_ITERATION; count_iter++)
	{
		if (current_x > right_board || current_x < left_board)
		{
			current_x -= h;
			if (fabs(h) < eps)
			{
				*x = previous_x;
				return count_iter;
			}
			h /= DIV;
			current_x += h;
			current_f = f(current_x);
			continue;
		}
		if (current_f < previous_f && previous_f >= previous_2f)
		{
			if (fabs(h) < eps)
			{
				*x = previous_x;
				return count_iter;
			}
			h /= (-DIV);
			previous_2f = previous_f;
			previous_x = current_x;
			current_x += h;
			previous_f = current_f;
			continue;
		}
		previous_x = current_x;
		current_x += h;
		previous_2f = previous_f;
		previous_f = current_f;
		current_f = f(current_x);
		
		if (fabs(h) < eps)
		{
			*x = previous_x;
			return count_iter;
		}
	}
	return -1;
}
