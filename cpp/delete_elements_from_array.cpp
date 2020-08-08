#include <fstream>
#include <limits>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdlib.h>


double* Read(std::ifstream& in, size_t& n) {
    if (!in.is_open()) {
        exit(1);
    }
    in >> n;
    double* a = static_cast<double*>(std::malloc(n * sizeof(double)));
    for (size_t i = 0; i < n; i++) {
        in >> a[i];
    }
    return a;
}


void Print(std::ofstream& out, double* arr, size_t n) {
    out << n << "\n";
    for (size_t i = 0; i < n; i++){
        out << arr[i] << " ";
    }
}

void ShiftElements1(double* arr, size_t n) {
    double inf = std::numeric_limits<double>::infinity();
    for (size_t l = 1, r = 1; l < n; l++) {
        while (r < n) {
            if (arr[l] != inf) break;
            if (arr[r] == inf || r <= l) 
                r++;
             else
                std::swap(arr[r], arr[l]);
        }
    }

}


void ShiftElements2(double* arr, size_t n) {
    double inf = std::numeric_limits<double>::infinity();
    size_t l = 1;
    size_t r = 1;
    while (l < n) {
        while (r < n) {
            if (l == n) break;
            if (arr[l] != inf) l++;
            if (arr[r] == inf || r <= l){ 
                r++;
            }
             else {
                 if (arr[l] == inf) {
                     std::swap(arr[r], arr[l]); 
                 }
             }              
        } 
        l++;
    }
}

size_t RemoveElements(double* arr, size_t n) {    
    double inf = std::numeric_limits<double>::infinity();
    size_t new_size = n;
    bool is_prev = false;
    
    for (size_t i = 1; i < n-1; i++) { 
        if (arr[i] < sqrt(arr[i+1]*arr[i-1]) && arr[i+1]*arr[i-1] >= 0) {
            --new_size;
            if (is_prev) {
                is_prev = true;
                arr[i-1] = inf;
            } else{
                is_prev = true;
            }
        } else {
            if (is_prev) {
                arr[i-1] = inf;
            }
            is_prev = false;
        }
    }
    ShiftElements1(arr, n);
    arr = (double*)(std::realloc(arr, new_size*sizeof(double)));
    return new_size;
}


int main() {
    size_t n; // size of the array
    double* arr; // pointer to the array
    std::ifstream in;
    in.open("input.txt");
    std::ofstream out;
    out.open("output.txt");
    arr = Read(in, n);
    n = RemoveElements(arr, n); //literaly we don't remove elements, we just move to right 
    Print(out, arr, n);
    free(arr);
    in.close();
    out.close();    
    return 0;
}