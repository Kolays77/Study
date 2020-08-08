#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

double function(double x, double y)
{
	return x * x * y;
}

double up_board(double x)
{
	return cos(x);
}

double down_board(double x)
{
	return sin(x);
}
