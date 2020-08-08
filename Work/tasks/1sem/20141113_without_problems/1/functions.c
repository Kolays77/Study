#include <stdio.h>
#include "head.h"

const int MAX_PRINTABLE_NUMBER = 100;

int number_is_prime(long long *prime_numbers, int number)
{
	int idx;
	for (idx = 2; prime_numbers[idx] * prime_numbers[idx] <= number; idx++)
	{
		if (number % prime_numbers[idx] == 0)
		{
			return 0; 	
		}
	}
	return 1;
} 

void fill_prime_numbers(long long *prime_numbers, int n)
{
	int idx, number;
	prime_numbers[1] = 2; prime_numbers[2] = 3;
	for (idx = 2; idx < n; idx++)
	{
		number = prime_numbers[idx] + 2;
		while (!number_is_prime(prime_numbers, number))
		{
			number += 2;
		}
		prime_numbers[idx + 1] = number; 
	}
	return;	
}

void print_array(long long *array, int n)
{
	int idx, m = (n > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : n);
	printf("FIRST %d NUMBERS:\n", n);
	for (idx = 1; idx <= m; idx++)
	{
		printf("%d. %lld\n", idx, array[idx]);
	}
	return;
}
