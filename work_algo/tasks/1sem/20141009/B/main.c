#include <stdio.h>
#include <stdlib.h>

void print_bits(unsigned int);
unsigned int max_number_1(unsigned int);

int main()
{
    unsigned int n = 0;
    printf("Input value ");
    scanf("%d", &n);
    print_bits(n);
    printf("Answer: %d\n", max_number_1(n));
    return 0;
}

void print_bits(unsigned int n)
{
    unsigned int length = sizeof(n) * 8;
    unsigned int idx;
    for (idx = 0; idx < length; idx++)
    {
        if ((n >> (length - idx - 1)) & 1)
        {
            break;
        }
    }
    printf("Bit introduction: ");
    for (; idx < length; idx++)
    {
        printf("%d", ((n >> (length - idx - 1)) & 1));
    }
    printf("\n");
    return;
}

unsigned int max_number_1(unsigned int n)
{
    unsigned int max_length = 0,
                 current_length = 0,
                 number_of_bits = sizeof(n) * 8,
                 idx;
    for (idx = 0; idx < number_of_bits; idx++)
    {
        unsigned int current_bit = n & 1;
        if (current_bit)
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
