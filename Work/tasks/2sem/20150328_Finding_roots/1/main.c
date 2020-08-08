#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "head.h"

#define EPS 0.0000000000000001

int main(int argc, char *argv[])
{
	double eps, left_board, right_board, counter_of_time;
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
	printf("Input [a]: ");
	if (scanf("%lf", &left_board) != 1)
	{
		printf("Cannot read [a]!\n");
		return 1;
	}
	printf("Input [b]: ");
	if (scanf("%lf", &right_board) != 1)
	{
		printf("Cannot read [b]!\n");
		return 1;
	}
	
	double (*f)(double);
	f = &function;
	
	counter_of_time = clock();
	
	double f_LEFT = f(left_board), f_RIGHT = f(right_board);
	if (f_LEFT * f_RIGHT > 0)
	{
		printf("f(a) and f(b) are equal signs!\n");
		return 0;
	}
	if (fabs(f_LEFT - EPS) < 0)
	{
		printf("x = %.3f\n", left_board);
		printf("f(x) = %e\n", f_LEFT);
		printf("Iteratopns = 1\n");
		printf("Elapsed = %.3f\n", (clock() - counter_of_time) / CLOCKS_PER_SEC);
		return 0;
	}
	if (fabs(f_RIGHT - EPS) < 0)
	{
		printf("x = %.3f\n", right_board);
		printf("f(x) = %e\n", f_RIGHT);
		printf("Iteratopns = 1\n");
		printf("Elapsed = %.3f\n", (clock() - counter_of_time) / CLOCKS_PER_SEC);
		return 0;
	}
	int result = find_root(f, left_board, right_board, eps, &answer);
	if (result < 0)
	{
		printf("Cannot solve!\n");
		return -1;
	}
	else
	{
		printf("x = %.3f\n", answer);
		printf("f(x) = %e\n", f(answer));
		printf("Iterations = %d\n", result);
		printf("Elapsed = %.3f\n", (clock() - counter_of_time) / CLOCKS_PER_SEC);
		return 0;
	}
}
