#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "head.h"

#define EPS 0.0000000000000001

int main(int argc, char *argv[])
{
	double x, h = 1;
	double (*f)(double);
	double counter_of_time;
	if (argc != 1)
	{
		printf("Usage: %s\n", argv[0]);
		return 1;
	}
	
	f = &function;
	
	while (h >= 0)
	{
		counter_of_time = clock();
		printf("Input x: ");
		if (scanf("%lf", &x) != 1)
		{
			printf("Cannot read [x]!\n");
			return 1;
		}
		printf("Input h: ");
		if (scanf("%lf", &h) != 1)
		{
			printf("Cannot read [h]!\n");
			return 1;
		}
		if (h < 0)
		{
			return 0;
		}
		
		calculate_differential(f, x, h);
		counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
		printf("Elapsed = %.3f\n\n", counter_of_time);
	}
	return 0;
}
