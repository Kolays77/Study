#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

double get_int_exp(int deg)
{
	double e = 1, cur_e;
	int count = 0, sign = 1;
	if (deg < 0)
	{
		deg = -deg;
		sign = -1;
	}
	while (deg > 0)
	{
		cur_e = M_E;
		count = 2;
		while (deg > count)
		{
			cur_e *= cur_e;
			count *= 2;
		}
		e *= cur_e;
		deg -= (count / 2);
		if (count == 1)
		{
			break;
		}
	}
	if (sign == -1)
	{
		e = 1 / e;
	}
	return e;
}

double get_exp(double x, double eps)
{
	double o = fabs(x), cur_exp = 1, cur_add = 1, factor = 1;
	
	for (factor = 1; o > eps; factor++)
	{
		cur_add *= (x / factor);
		cur_exp += cur_add;
		o *= x;
	}
	return cur_exp;
}
