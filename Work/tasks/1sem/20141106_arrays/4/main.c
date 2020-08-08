#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"

int main(void)
{
	const char *name1 = "a.txt", *name2 = "b.txt";
	int n, m, key;
	int result;
	double *a, *b;
	double counter_of_time;
	
	printf("Input n: ");
	if (scanf("%d", &n) != 1)
	{
		printf("Input Error!\n");
		return -1;
	}
	if (n <= 0)
	{
		printf("n must be more than 0!\n");
		return 1;
	}
	printf("Input key1: ");
	if (scanf("%d", &key) != 1)
	{
		printf("Input Error!\n");
		return -1;
	}
	if (!(a = (double *) malloc(n * sizeof(double))))
	{
		printf("Not enough memory!\n");
		return -4;
	}
	if (key == 0)
	{
		result = read_array(name1, a, n);
		if (result < 0)
		{
			return_error(result, name1);
			free(a);
			return -1;
		}
		n = result;
	}
	else
	{
		init_array(a, n, key);
	}
	printf("ARRAY a:\n");
	print_array(a, n);
	
	printf("Input m: ");
	if (scanf("%d", &m) != 1)
	{
		printf("Input Error!\n");
		return -1;
	}
	printf("Input key2: ");
	if (scanf("%d", &key) != 1)
	{
		printf("Input Error!\n");
		return -1;
	}
	
	if (!(b = (double *) malloc(m * sizeof(double))))
	{
		printf("Not enough memory!\n");
		return -4;
	}
	if (key == 0)
	{
		result = read_array(name2, b, m);
		if (result < 0)
		{
			return_error(result, name2);
			free(b);
			return -1;
		}
		m = result;
	}
	else
	{
		init_array(b, m, key);
	}
	
	printf("ARRAY b:\n");
	print_array(b, m);
	
	counter_of_time = clock();
	search_a_in_b(a, b, n, m);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	
	printf("NEW ARRAY a:\n");
	print_array(a, n);
	printf("Elapsed = %.2lf\n", counter_of_time);
	return 0;
}
