#include "headers/random_collections.h"
#include "headers/print_collections.h"
#include <iostream>
#include <algorithm>

//with temporary array memory O(k) and O(n-k) access;
int ShiftElementsRight(double* array, size_t n, size_t k = 1) {
    int count = k;
    double* temp_arr = new double[n];
    for (int i = 0; i < k; i++) 
        temp_arr[i] = array[n - i - 1];
    
    
    for (size_t i = n; i > k; i--) {
        array[i] = array[i - k];
        count++;
    }

    for (int i = 0; i < k; i++)
        array[i] = temp_arr[i];
    delete [] temp_arr;
    return count;
}


//доделать
void Rotate(double* array, int n, int  k) {
    if (k == 0 || n < 2) { 
        return;
    }
    k = k % n;
    for (int i = 0; i < k; i++) {
        Print(array, n);
        std::swap(array[i], array[n - k + i]);
    }
    int left = k; 
    if (n - k == k || n == 2) {
        return;
    }
    /*
    while (left < k) {
        left += k;
        for (int i = 0; i < k; i++) {
            std::swap(array[left + i], array[n - k + i]);
        }
    }
    */
}


// STL-implemetation 
void ShiftElementsRight_std(double* array, size_t n, size_t k = 1) {
    std::rotate(array, array + n - k, array + n);
}

// O(n) - access arr / O(1) memory
void rotate(double* nums, int n, int k) {
    int nowIndex = 0, nextIndex;
    double tmp1, tmp2 = nums[0];
    for(int j=0,i=0; j<n; j++){
        tmp1 = tmp2;
        nowIndex = (k + nowIndex) % (n);
        tmp2 = nums[nowIndex];
        nums[nowIndex] = tmp1;
        if(nowIndex == i) {
            nowIndex = ++i;
            tmp2 = nums[nowIndex];
        }
	}
}

int main() {
    int n = 5; 
    double* array = new double[n];
    for (int i = 0; i < n; i++) {
        array[i] = i + 1;
    }
    
    //Print(array, n);
    //ShiftElementsRight_std(array, n, 5);
    Rotate(array, n, 2);
    //Print(array, n);
    delete [] array;
}
