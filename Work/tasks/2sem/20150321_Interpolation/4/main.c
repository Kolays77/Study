#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "read.h"
#include "head.h"

int main(int argc, char **argv)
{
	char *name = "a.txt";
	int n, result;
	double *x, *func, *dif, x0;
	double counter_of_time, answer;
	
	if (argc != 3)
	{
		printf("Usage: %s [n] [<file>]\n", argv[0]);
		return 1;
	}
	if ((n = atoi(argv[1])) <= 0)
	{
		printf("Cannot read [n]!\n");
		return 1;
	}
	
	name = argv[2];
	
	if (!(x = (double *) malloc(n * sizeof(double))) ||
		!(func = (double *) malloc(n * sizeof(double))) ||
		!(dif = (double *) malloc(n * sizeof(double))))
	{
		printf("Not enough memory!\n");
		return 2;
	}
	
	result = read(name, x, func, dif, n);
	if (result < 0)
	{
		return_error(result, name);
		free(x);
		free(func);
		free(dif);
		return 3;
	}
	print_function(x, func, dif, n);
	
	printf("Input x0: ");
	if (!scanf("%lf", &x0))
	{
		printf("Input Error!\n");
		return -1;
	}
	
	counter_of_time = clock();
	if (!make_f(x, func, dif, n))
	{
		return 0;
	}
	answer = calculate_answer(x, func, dif, n, x0);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	printf("ANSWER: f(%.3f) = %.3f\n", x0, answer);
	printf("Elapsed = %.3f\n", counter_of_time);
	free(x);
	free(func);
	free(dif);
	return 0;
}
