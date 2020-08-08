#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"

int main(void)
{
	int n;
	long long *prime_numbers;
	double counter_of_time;
	printf("Input n: ");
	if (scanf("%d", &n) != 1)
	{
		printf("Input Error!\n");
		return -1;
	}
	if (!(prime_numbers = (long long *) malloc(n * sizeof(long long))))
	{
		printf("Not enough memory!\n");
		return -2;
	}
	counter_of_time = clock();
	fill_prime_numbers(prime_numbers, n);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	print_array(prime_numbers, n);
	printf("Elapsed = %.2lf\n", counter_of_time);
	return 0;
}
