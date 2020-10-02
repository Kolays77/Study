#include <stdio.h>
#include <stdlib.h>

int get_exp(double);

int main()
{
    double x;
    printf("Enter x >= 0\nx = "); scanf("%lf", &x);
    if (x < 0)
    {
        printf("x must be less than 0!\n");
        return 0;
    }
    printf("[log_2(x)] = ");
    if (x == 0)
    {
        printf("-INFINITY\n");
	return 0;
    }
    if (x >= 1)
    {
        printf("%d\n", get_exp(x));
    }
    else
    {
        printf("%d\n", (-1) * get_exp(1 / x));
    }
    return 0;
}

int get_exp(double x)
{
    int exp = 0;
    double current_degree = 1;
    while (current_degree <= x)
    {
        exp++;
        current_degree *= 2;
    }
    return exp - 1;
}
