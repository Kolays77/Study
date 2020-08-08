#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

double get_ln(double x, double eps)
{
	double o = fabs(x), cur_ln = 0, cur_add = --x, divider = 1;
	for (divider = 1; o > eps; divider++)
	{	
		cur_ln += cur_add / divider;
		cur_add *= (-x);
		o *= x;
	}
	return cur_ln;
}
