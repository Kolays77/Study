#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

double get_sin(double x, double eps)
{
	double o = fabs(x), sin_x = x, cur_add = x, cur_factor;
	
	for (cur_factor = 3; o > eps; cur_factor += 2)
	{
		cur_add *= (-x * x / (cur_factor * (cur_factor - 1)));
		sin_x += cur_add;
		o *= x;
	}
	return sin_x;
}

double get_cos(double x, double eps)
{
	double o = fabs(x), cos_x = 1, cur_add = 1, cur_factor;
	
	for (cur_factor = 2; o > eps; cur_factor += 2)
	{
		cur_add *= (-x * x / (cur_factor * (cur_factor - 1)));
		cos_x += cur_add;
		o *= x;
	}
	return cos_x;
}
