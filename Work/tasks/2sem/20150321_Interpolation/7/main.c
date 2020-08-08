#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "head.h"

#define EPS 0.00000000000001

int main(void)
{
	double x, exp_x = 0, eps = 1, real_exp_x;
	int int_x;
	while (eps >= 0)
	{
		printf("Input [x]: ");
		if (scanf("%lf", &x) != 1)
		{
			printf("Cannot read [x]!\n");
			return 1;
		}
		printf("Input [eps]: ");
		if (scanf("%lf", &eps) != 1)
		{
			printf("Cannot read [eps]!\n");
			return 1;
		}
		real_exp_x = exp(x);
		int_x = (int) x;
		x -= int_x;
		if (x < 0)
		{
			x++;
			int_x--;
		}
		exp_x = get_int_exp(int_x);
		exp_x *= get_exp(x, EPS);
		printf("exp(x) = %.3f; eps = %.5f\n\n", exp_x, fabs(exp_x - real_exp_x));
	}
	
	return 0;
}
