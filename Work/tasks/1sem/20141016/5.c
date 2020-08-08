#include <stdio.h>
#include <stdlib.h>

const long long N = 13; //при больших n из-за точности ответ такой же

double task5(long long);

int main(void)
{
	long long n;
	printf("n = ");
	if (!scanf("%lld", &n))
	{
		printf("Input Error\n");
		return 0;
	}
	printf("sum = %lf\n", task5(n));
	return 0;
}

double task5(long long n)
{
	double sum = 0, addend = 1;
	long long k;
	n = (((n) < (N)) ? (n) : (N));
	for (k = 1; k <= n; k++)
	{
		addend *= 2;
		addend /= k;
		sum += addend;
	}
	return sum;
}
