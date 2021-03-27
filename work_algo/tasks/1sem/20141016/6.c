#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_number_prime(long long);
long long num_of_prime_numbers(long long);

int main(void)
{
    long long n;
	printf("n = ");
	if (!scanf("%lld", &n))
	{
		printf("Input error\n");
		return 0;
	}
    printf("number = %lld\n", num_of_prime_numbers(n));
    return 0;
}

bool number_is_prime(long long n) {
    double sqrt_n = sqrt(n);
    int i;
    for (i = 2; i <= sqrt_n; i++)
    {
		if (n % i == 0)
		{
			return false;
		}
    }
    return true;
}

long long num_of_prime_numbers(long long n)
{
    long long num = 0, current = 2;
    if (n <= 0)
    {
		return num;
	}
    while (current != n)
    {
		if (number_is_prime(current))
		{
			num++;
		}
		current++;
	}
    return num;
}
