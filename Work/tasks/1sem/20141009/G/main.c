#include <stdio.h>
#include <stdlib.h>

void print_bits(unsigned int);
unsigned int get_left_significant(unsigned int, unsigned int);
unsigned int change_0(unsigned int);

int main()
{
    unsigned int n = 0;
    printf("Give me a value ");
    scanf("%d", &n);
    printf("    "); print_bits(n);
    unsigned int answer = change_0(n);
    printf("New "); print_bits(answer);
    printf("Answer: %d\n", answer);
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

unsigned int get_left_significant(unsigned int n,
                                  unsigned int number_of_bits)
{
    unsigned int left_significant;
    for (left_significant = number_of_bits - 1; left_significant >= 0; left_significant--)
    {
        if ((n >> left_significant) & 1)
        {
            break;
        }
    }
    return left_significant;
}

unsigned int change_0(unsigned int n)
{
    unsigned int number_of_bits = sizeof(n) * 8,
                 result = (n & 1);
    if (n == 0)
        return 0;
    unsigned int left_significant = get_left_significant(n, number_of_bits);
    unsigned int idx;
    for (idx = 1; idx < left_significant; idx++)
    {
        if (!((n >> (idx - 1)) & 1) &&
            !((n >> idx) & 1) &&
            !((n >> (idx + 1)) & 1))
        {
            result += (1 << idx);
        }
        else
        {
            result += (((n >> idx) & 1) << idx);
        }
    }
    result += (((n >> idx) & 1) << idx);
    return result;
}
