#include <iostream>
#include <chrono>
#include <random>


//comparator: prime test
bool isPrime(int value) {   
    for (size_t i = 2; i < value; i++) {
        if (value % i == 0)
            return false;
    }
    return value > 1;
 }


size_t CountElements(int* array, size_t n, bool isFunc(int)) {
    size_t count = 0;
    for (size_t i = 0; i < n; i++) {
        if ((array[i]) > 2) {
            count++;
        }
    }
    return count;
}

int* GenerateArray(size_t n) {
    int* arr = new int[n];
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> dist(0, n);  
    for (size_t i = 0; i < n; i++) {
        arr[i] = dist(rng);
    }
    return arr;
}

template<typename T>
int CountLocalMaximum(T* array, size_t n) {
    int count = 0;
    if ( n >= 0 && n <= 2) {
        return -1;
    }
    for (size_t i = 0; i < n; i++) {
        if (i == 0 || i == (n - 1)) {
            continue;
        } else {
            if (array[i] > array[i + 1] && array[i] > array[i - 1]) {
                count++;
                std::cout << "[" << i << "] = " << array[i] << std::endl;
            }
        }

    }
    return count;
}

int main (){
    size_t  n = 4;
    int* array = GenerateArray(n); //dynamic array
    for (size_t i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    //std::cout << CountElements(array, n, isPrime) << '\n';
    std::cout << CountLocalMaximum(array, n) << '\n';
    delete [] array;
    return 0;
}