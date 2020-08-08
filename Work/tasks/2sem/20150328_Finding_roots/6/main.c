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
	double (*f)(double);
	double h;
	double *d, *pointer1, *pointer2;
	int m, idx;
	if (argc != 3)
	{
		printf("Usage: %s [eps] [m]\n", argv[0]);
		return 1;
	}
	if ((eps = atof(argv[1])) <= 0)
	{
		printf("Cannot read [eps]!\n");
		return 1;
	}
	if ((m = atoi(argv[2])) <= 0)
	{
		printf("Cannot read [m]!\n");
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
	
	if (!(d = (double *) malloc((3 * m + 1) * sizeof(double))))
	{
		printf("Not enough memory!\n");
		return 2;
	}
	f = &function;
	d[0] = left_board;
	d[m + 1] = d[2 * m + 1] = f(d[0]);
	pointer1 = d + m + 1;
	pointer2 = d + 2 * m + 1;
	h = (right_board - left_board) / (m - 1);
	for (idx = 1; idx < m; idx++)
	{
		d[idx] = d[idx - 1] + h;
		pointer2[idx] = pointer1[idx] = f(d[idx]);
	}
	
	counter_of_time = clock();
	
	int result = find_root(d, m, f, eps, &answer);
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
