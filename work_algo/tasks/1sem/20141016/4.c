#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const long long N = 7.5e5; //при больших n из-за точности модуль ответа такой же

double task4(long long);

int main()
{
	long long n;
	printf("n = ");
	if (!scanf("%lld", &n))
	{
		printf("Input Error\n");
		return 0;
	}
	printf("answer = %lf\n", task4(n));
	return 0;
}

double task4(long long n)
{
	double sum = 0;
	long long k;
	int num_is_odd = -1;
	n = (((n) < (N)) ? (n) : (N));
	for (k = 1; k <= n; k++, num_is_odd *= (-1))
	{
		sum += (double) num_is_odd / k;
	}
	return sum;
}
