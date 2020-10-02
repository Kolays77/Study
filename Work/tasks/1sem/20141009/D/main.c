#include <stdio.h>
#include <stdlib.h>

void print_bits(unsigned int);
unsigned int max_distance_1(unsigned int);

int main()
{
    unsigned int n = 0;
    printf("Give me a value ");
    scanf("%d", &n);
    print_bits(n);
    printf("Answer: %d\n", max_distance_1(n));
    return 0;
}

void print_bits(unsigned int x)
{
    unsigned int length = sizeof(x) * 8;
    unsigned int idx;
    for (idx = 0; idx < length; idx++)
    {
        if ((x >> (length - idx - 1)) & 1)
        {
            break;
        }
    }
    printf("Bit introduction ");
    for (; idx < length; idx++)
    {
        printf("%d", ((x >> (length - idx - 1)) & 1));
    }
    printf("\n");
    return;
}

unsigned int max_distance_1(unsigned int n)
{
    unsigned int number_of_bits = sizeof(n) * 8,
                 right_significant = 0,
                 left_significant = 0;
    if (n == 0)
        return 0;
    for (left_significant = number_of_bits - 1; left_significant >= 0; left_significant--)
    {
        if ((n >> left_significant) & 1)
        {
            break;
        }
    }
    for (right_significant = 0; right_significant <= left_significant; right_significant++)
    {
        if (n & 1)
        {
            break;
        }
        n >>= 1;
    }
    return left_significant - right_significant;
}
