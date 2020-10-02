#include <stdio.h>
#include <stdlib.h>

void print_bits(unsigned int);
unsigned int max_number_0(unsigned int);

int main()
{
    unsigned int n = 0;
    printf("Give me a value ");
    scanf("%d", &n);
    print_bits(n);
    printf("Answer: %d\n", max_number_0(n));
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

unsigned int max_number_0(unsigned int n)
{
    if (n == 0)
        return 0;
    unsigned int max_length = 0,
                 current_length = 0,
                 number_of_bits = sizeof(n) * 8,
                 i,
                 left_significant;
    for (left_significant = number_of_bits - 1; left_significant >= 0; left_significant--)
    {
        if ((n >> left_significant) & 1)
        {
            break;
        }
    }
    for (i = 0; i <= left_significant; i++)
    {
        unsigned int current_bit = n & 1;
        if (!current_bit)
        {
            current_length++;
        }
        else
        {
            if (current_length > max_length)
            {
                max_length = current_length;
            }
            current_length = 0;
        }
        n >>= 1;
    }
    if (current_length > max_length)
    {
        max_length = current_length;
    }
    return max_length;
}

