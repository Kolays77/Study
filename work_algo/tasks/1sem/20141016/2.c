#include <stdio.h>
#include <stdlib.h>

long long sec2(int);

int main(void)
{
	int n;
	printf("n = ");
	if (!scanf("%d", &n))
	{
		printf("Input error\n");
		return 0;
	}
	if (n < 0)
	{
		printf("Input n: n > 0\n");
		return 0;
	}
	printf("x[n] = %lld\n", sec2(n));
	return 0;
}

long long sec2(int n)
{
	int prev1 = 2, prev2 = 9, i;
	long long cur_exp = 4, current = 0;
	if (n == 0)
	{
		return prev1;
	}
	if (n == 1)
	{
		return prev2;
	}
	for (i = 2; i <= n; i++)
	{
		current = prev2 * 5 - prev1 * 6 + cur_exp;
		cur_exp *= 4;
		prev1 = prev2;
		prev2 = current;
	}
	return current;
}
