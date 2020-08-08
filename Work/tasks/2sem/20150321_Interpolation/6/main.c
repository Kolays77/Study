#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "head.h"

#define EPS 0.000001

int main(void)
{
	double n;
	double x, cos_x, real_cos_x, eps = 1, sign = 1;
		
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
		real_cos_x = cos(x);
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
			sign *= -1;
		}
		if (x > 1 - EPS)
		{
			x /= 2;
			cos_x = get_cos(x, eps);
			cos_x = 2 * cos_x * cos_x - 1;
		}
		else
		{
			cos_x = get_cos(x, eps);
		}
		cos_x *= sign;
		printf("cos(x) = %.3f; eps = %.5f\n\n", cos_x, fabs(cos_x - real_cos_x));
	}
	
	return 0;
}
