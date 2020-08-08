#include <stdio.h>
#include <stdlib.h>

const long long N = 10; //при больших n из-за точности ответ такой же

double task3(long long);

int main(void)
{
	long long n;
	printf("n = ");
	if (!scanf("%lld", &n))
	{
		printf("Input Error\n");
		return 0;
	}
	printf("answer = %lf\n", task3(n));
	return 0;
}

double task3(long long n)
{
	double sum = 0, addend = 1;
	long long k;
	n = (((n) < (N)) ? (n) : (N));
	for (k = 1; k <= n; k++)
	{
		addend /= k;
		sum += addend;
	}
	return sum;
}
