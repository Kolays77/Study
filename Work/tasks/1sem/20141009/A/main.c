#include <stdio.h>
#include <stdlib.h>

void print_bits(unsigned int);
unsigned int reverse_bits(unsigned int);

int main()
{
    unsigned int n = 0;
    printf("Input value ");
    scanf("%d", &n);
    unsigned int answer = reverse_bits(n);
    print_bits(n);
    printf("Reverse "); print_bits(answer);
    printf("Answer: %d\n", answer);
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
    printf("Bit representation ");
    for (; idx < length; idx++)
    {
        printf("%d", ((n >> (length - idx - 1)) & 1));
    }
    printf("\n");
    return;
}

unsigned int reverse_bits(unsigned int n)
{
    unsigned int result = 0, first_significant, max_length = sizeof(n) * 8;
    if (n == 0)
        return 0;
    for (first_significant = max_length - 1; first_significant >= 0; first_significant--)
    {
        if ((n >> first_significant) & 1)
        {
            break;
        }
    }
    unsigned int idx;
    for (idx = 0; idx <= first_significant; idx++)
    {
        result += ((n & 1) << (first_significant - idx));
        n >>= 1;
    }
    return result;
}
