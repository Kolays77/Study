#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "head.h"

int main(int argc, char *argv[])
{
	double a, eps = 0;
	double result;
	
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
		counter_of_time = clock();
		if (calculate_integral(f, a, &result, eps) < 0)
		{
			printf("Integral does not exist!\n\n");
		}
		else
		{
			printf("I = %.10f\n", result);
			printf("Elapsed = %.3f\n\n", (clock() - counter_of_time) / CLOCKS_PER_SEC);
		}
	}
	return 0;
}
