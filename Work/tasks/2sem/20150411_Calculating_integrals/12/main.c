#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "head.h"

int main(int argc, char *argv[])
{
	double a, b, eps = 0;
	double result;
	
	if (argc != 1)
	{
		printf("Usage: %s\n", argv[0]);
		return 1;
	}
	
	double (*x)(double);
	x = &coord1;
	double (*y)(double);
	y = &coord2;
	double counter_of_time;
	
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
		printf("Input b: ");
		if (scanf("%lf", &b) != 1)
		{
			printf("Cannot read [b]!\n");
			return 1;
		}
		counter_of_time = clock();
		if (calculate_length(x, y, a, b, eps, &result) < 0)
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
