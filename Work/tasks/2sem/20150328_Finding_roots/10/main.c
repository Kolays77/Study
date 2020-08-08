#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "head.h"

#define EPS 0.0000000000000001

int main(int argc, char *argv[])
{
	double eps, x0, x2, x1, counter_of_time;
	double answer;
	if (argc != 2)
	{
		printf("Usage: %s [eps]\n", argv[0]);
		return 1;
	}
	if ((eps = atof(argv[1])) <= 0)
	{
		printf("Cannot read [eps]!\n");
		return 1;
	}
	printf("Input [x0]: ");
	if (scanf("%lf", &x0) != 1)
	{
		printf("Cannot read [x0]!\n");
		return 1;
	}
	printf("Input [x2]: ");
	if (scanf("%lf", &x2) != 1)
	{
		printf("Cannot read [x2]!\n");
		return 1;
	}
	
	double (*f)(double);
	f = &function;
	
	x1 = (x2 + x0) / 2;
	counter_of_time = clock();
	
	int result = find_max(x0, x2, x1, f, eps, &answer);
	if (result < 0)
	{
		printf("Cannot solve!\n");
		return -1;
	}
	else
	{
		printf("x = %.3f\n", answer);
		printf("f(x) = %5f\n", f(answer));
		printf("Iterations = %d\n", result);
		printf("Elapsed = %.3f\n", (clock() - counter_of_time) / CLOCKS_PER_SEC);
		return 0;
	}
}
