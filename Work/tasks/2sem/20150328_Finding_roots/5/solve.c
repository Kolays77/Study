#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

#define MAX_ITERATION 100000
#define EPS 0.0000000000000001

double function(double x)
{
	return x*x -2*x -159;
}

int find_root(double x0,
              double x2,
              double x1,
              double (*f)(double),
              double eps,
              double *answer)
{
	int count_iter;
	double y0 = f(x0), y1 = f(x1), y2 = f(x2), y3 = 1, f_01, f_12, f_012, x3 = 0;
	
	(void) answer;
	for (count_iter = 0; count_iter < MAX_ITERATION; count_iter++)
	{
		//printf("%f  %f  %f\n", fabs(y1 - y0), fabs(y2 - y0), fabs(y1 - y2));
		if (fabs(y1 - y0) < EPS || fabs(y2 - y0) < EPS || fabs(y1 - y2) < EPS)
		{
			return -1;
		} 
		f_01 = (x1 - x0) / (y1 - y0);
		f_12 = (x2 - x1) / (y2 - y1);
		f_012 = (f_12 - f_01) / (y2 - y0);
	//printf("%f %f %f oooooooo\n", y0, y1, y2);
		x3 = x0 - y0 * f_01 + y0 * f_012 * y1;
		y3 = f(x3);
		//printf("%f %f\n", x3, y3);
		if (fabs(y3) < eps)
		{
			break;
		}
		if (y3 >= y0 && y3 >= y1 && y3 >= y2)
		{
			return -1;
		}
		if (y2 > y0 && y2 > y1)
		{
			x2 = x3;
			y2 = y3;
			continue;
		}
		if (y1 > y0)
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
