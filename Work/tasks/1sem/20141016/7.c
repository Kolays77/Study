#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_number_prime(long long);
long double sum_of_prime_numbers(long long);

int main(void)
{
    long long n;
	printf("n = ");
	if (!scanf("%lld", &n))
	{
		printf("Input error\n");
		return 0;
	}
    printf("sum = %Lf\n", sum_of_prime_numbers(n));
    return 0;
}

bool number_is_prime(long long n) {
    double sqrt_n = sqrt(n);
    long long i;
    for (i = 2; i <= sqrt_n; i++)
    {
		if (n % i == 0)
		{
			return false;
		}
    }
    return true;
}

long double sum_of_prime_numbers(long long n)
{
    long double sum = 0;
    long long cnt = 0, current = 2;
    if (n <= 0)
    {
		return sum;
	}
    while (cnt != n)
    {
		if (number_is_prime(current))
		{
			sum += current;
			cnt++;
		}
		current++;
	}
    return sum;
}
