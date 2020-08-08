#include "headers/random_collections.h"
#include "headers/print_collections.h"
#include <iostream>
#include <algorithm>

int main() {
    size_t n = 25;
    int* a = Random::Array<int>(n,-3,4);
    Print(a,n);
    size_t i, q;
    for (q = i = 0; q < n; ++q)
        if (a[q] != 4)
            a[i++] = a[q];

    for (; i<n; ++i)
        a[i] = 0;
    
    Print(a,n);
    delete [] a;
    return 0;   
}