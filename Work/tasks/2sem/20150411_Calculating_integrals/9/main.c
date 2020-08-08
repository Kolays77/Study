#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "head.h"

#define EPS 0.0000000000000001

int main(int argc, char *argv[])
{
	double a, b, eps = 0;
	double (*f)(double);
	double counter_of_time;
	
	if (argc != 1)
	{
		printf("Usage: %s\n", argv[0]);
		return 1;
	}
	
	f = &function;
	
	while (eps >= 0)
	{
		counter_of_time = clock();
		printf("Input [eps]: ");
		if (scanf("%lf", &eps) != 1)
		{
			printf("Cannot read [eps]!\n");
			return 1;
		}
		if (eps < 0)
		{
			return 0;
		}
		printf("Input a: ");
		if (scanf("%lf", &a) != 1)
		{
			printf("Cannot read [a]!\n");
			return 1;
		}
		printf("Input b: ");
		if (scanf("%lf", &b) != 1)
		{
			printf("Cannot read [b]!\n");
			return 1;
		}
		calculate_integral(f, a, b, eps);
		counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
		printf("Elapsed = %.3f\n\n", counter_of_time);
	}
	return 0;
}
