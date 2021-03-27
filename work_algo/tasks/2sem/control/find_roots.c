#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

#define EPS 0.00000000001

double calculate(double x)
{
	return calculate_integral(x, down_board(x), up_board(x), EPS);
}

int findroots(double a,
              double b)
{
	int number_of_roots = 0;
	int idx;
	double step = 0.1, x, x_left = a, x_right;
	double _left = calculate(a), _right;
	
	for (idx = 1; a + idx * step <= b; idx++)
	{
		x_right = a + idx * step;
		_right = calculate(x_right);
		if (_left * _right <= 0)
		{
			x = binsearch(x_left, x_right, _left, _right);
			printf("%d. x = %.10f; Residual = %e\n", ++number_of_roots, x, calculate(x));
		}
		x_left = x_right;
		_left = _right;
	}
	
	return number_of_roots;
}

double binsearch(double x_left,
                 double x_right,
                 double _left,
                 double _right)
{
	double x_middle, _middle;
	while (fabs(_right - _left) > EPS)
	{
		x_middle = (x_right + x_left) / 2;
		_middle = calculate(x_middle);
		if (_left * _middle <= 0)
		{
			x_right = x_middle;
			_right = _middle;
		}
		else
		{
			x_left = x_middle;
			_left = _middle;
		}
	}
	return (x_right + x_left) / 2;
}
