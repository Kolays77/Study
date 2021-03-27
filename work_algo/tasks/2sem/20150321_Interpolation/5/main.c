#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "head.h"

#define EPS 0.000001

int main(void)
{
	double n;
	double x, sin_x, real_sin_x, eps = 1, sign = 1;
		
	while (eps > 0)
	{
		sign = 1;
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
		real_sin_x = sin(x);
		n = x / (2 * M_PI);
		n = floor(n);
		x -= (2 * M_PI * n);
		if (x > M_PI)
		{
			x -= M_PI;
			sign *= -1;
		}
		if (x > M_PI / 2)
		{
			x = M_PI - x;
		}
		if (x > 1 - EPS)
		{
			x /= 2;
			sin_x = get_sin(x, eps);
			sin_x = 2 * sin_x * sqrt(1 - sin_x * sin_x);
		}
		else
		{
			sin_x = get_sin(x, eps);
		}
		sin_x *= sign;
		printf("sin(x) = %.3f; eps = %.5f\n\n", sin_x, fabs(sin_x - real_sin_x));
	}
	
	return 0;
}
