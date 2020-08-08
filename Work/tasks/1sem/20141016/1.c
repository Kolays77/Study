#include <stdio.h>
#include <stdlib.h>

long long sec(long long);

int main(void)
{
    long long n;
    printf("n = ");
    if (!scanf("%lld", &n))
	{
		printf("Input error\n");
		return 0;
	}
	if (n < 0)
	{
		printf("Input n: n > 0\n");
		return 0;
	}
    printf("x[n] = %lld\n", sec(n));
    return 0;
}

long long sec(long long n)
{
    long long x_i = 1, deg_i = 4 * 1, i;
    for (i = 1; i <= n; i++)
    {
        deg_i *= 2;
        x_i = x_i * 3 + deg_i;
    }
    return x_i;
}
