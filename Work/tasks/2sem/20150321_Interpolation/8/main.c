#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "head.h"

#define EPS 0.00000000000001

int main(void)
{
	double x, ln_x = 0, eps = 1, real_ln_x;
	int int_deg2 = 0;
	while (eps >= 0)
	{
		int_deg2 = 0;
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
		real_ln_x = log(x);
		while (x >= 2)
		{
			x /= 2;
			int_deg2++;
		}
		ln_x = M_LN2 * int_deg2 + get_ln(x, eps);
		printf("ln(x) = %.3f; eps = %.5f\n\n", ln_x, fabs(ln_x - real_ln_x));
	}
	
	return 0;
}
