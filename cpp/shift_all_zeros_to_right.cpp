#include "headers/random_collections.h"
#include "headers/print_collections.h"
#include <iostream>
#include <algorithm>

int main() {
    size_t n = 13;
    int a[] = {1,0,0,0,0,0,2,23,45,5,6,7,8};
    Print(a,n);
    int elem = 0;
    size_t i, q;
    for (q = i = 0; q < n; ++q)
        if (a[q] != elem)
            a[i++] = a[q];

    for (; i<n; ++i)
        a[i] = elem;
    
    Print(a,n);
    return 0;   
}