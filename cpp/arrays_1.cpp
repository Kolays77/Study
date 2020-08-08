#include "headers/random_collections.h"
#include "headers/print_collections.h"
#include <iostream>


int main() {
    uint n = 10; 
    double* array = Random::Array<double>(n, 0, n);
    Print(array, n);
    double prev = array[0];
    double temp;

    for (size_t i = 1; i <= n -1; i++) {
        temp = array[i-1];
        array[i-1] = prev;
        prev = (temp + array[i+1]) / 2;
        
    }

    Print(array, n);
    delete [] array;
}
