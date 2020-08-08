#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "read.h"
#include "head.h"

int main(int argc, char **argv)
{
	char *name = "a.txt";
	int n, result;
	double *x, *y, x0;
	double counter_of_time, answer;
	
	if (argc != 4)
	{
		printf("Usage: %s [n] [x0] [<file>]\n", argv[0]);
		return 1;
	}
	if ((n = atoi(argv[1])) <= 0)
	{
		printf("Cannot read [n]!\n");
		return 1;
	}
	if ((x0 = atof(argv[2])) <= 0)
	{
		printf("Cannot read [x0]!\n");
		return 1;
	}
	
	name = argv[3];
	
	if (!(x = (double *) malloc(n * sizeof(double))) ||
		!(y = (double *) malloc(n * sizeof(double))))
	{
		printf("Not enough memory!\n");
		return 2;
	}
	
	result = read(name, x, y, n);
	if (result < 0)
	{
		return_error(result, name);
		free(x);
		free(y);
		return 3;			
	}

	print_function(x, y, n);
	counter_of_time = clock();
	answer = solve(x, y, n, x0);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	printf("ANSWER: %.3f\n", answer);
	printf("Elapsed = %.3f\n", counter_of_time);
	free(x);
	free(y);
	return 0;
}
