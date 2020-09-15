#include <iostream>
#include <vector>

#define PRINT

// END - NOT inclusive
template<typename T>
void QuickSort(T begin, T end) {
    2+2;
}

// END - NOT inclusive
template<typename T>
void InsertionSort(T begin, T end) {
    for (T i = begin; i != end; ++i) {
        T j = i;
        while (j > begin && *(j) < *(j - 1)) {
            std::swap(*(j), *(j - 1));
            --j;
        }
    }
}


/* version2
// END - NOT inclusive
template<typename T>
void InsertionSort(T begin, T end) {
	int size = end - begin;
	for (int i = 1; i < size; ++i) {
		int j = i;
		while (j && *(begin + j) < *(begin + j - 1)) {
			std::swap(*(begin + j), *(begin + j - 1));
			--j;
		}
	}
}
*/

// END - NOT inclusive
template<typename T>
void BubbleSort(T begin, T end) {
    size_t size = end - begin;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (*(begin + i) > *(begin + j))
                std::swap(*(begin + i), *(begin + j));
        }
    }
}

// END - NOT inclusive //онли
template<typename T>
void Merge(T* array, size_t l, size_t m, size_t r, size_t& count) {
	size_t n1 = m - l + 1;
    size_t n2 = r - m;
    T* left = new T[n1];
    T* right = new T[n2];
    for (size_t i = 0; i < n1; ++i) {
        left[i] = array[l + i];
    }

    for (size_t i = 0; i < n2; ++i) {
        right[i] = array[m + i + 1];
    }
    size_t i = 0;
    size_t j = 0;
    size_t k = l;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            ++i;
        } else {
            array[k] = right[j];
            ++j;
			count += (n1 - i);
        }
        ++k;
    }

    while (i < n1) {
        array[k] = left[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        array[k] = right[j];
        ++j;
        ++k;
    }

    delete [] left;
    delete [] right;
}

// END - inclusive !!
template<typename T>
void MergeSort(T array, size_t l, size_t r, size_t& count) {
	if (l < r) {
        size_t m = (r + l) / 2;
        MergeSort(array, l, m, count);
        MergeSort(array, m + 1, r, count);
        Merge(array, l, m, r, count);
    }
}

template<typename T>
void Sort(T* begin, T* end, const std::string& method = "bubble") {
    if ( method == "bubble") {
        BubbleSort(begin, end);
    } else if (method == "insertion") {
        InsertionSort(begin, end);
    } else if (method == "quick") {
        QuickSort(begin, end);
    } else if (method == "merge") {
        MergeSort(begin, 0, end - begin - 1);
    }
}



int Partition (int arr[], int low, int high) {  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element   
    for (int j = low; j <= high - 1; j++) {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  {  
            ++i; // increment index of smaller element  
            std::swap(arr[i], arr[j]);  
        }  
    }  
    std::swap(arr[i + 1], arr[high]);  
    return (i + 1);  
}  

void QuickSort(int arr[], int low, int high) {  
    if (low < high) {  
        int pivot = Partition(arr, low, high);   
        QuickSort(arr, low, pivot - 1);  
        QuickSort(arr, pivot + 1, high);  
    }  
}  

void Print(int arr[], size_t size) {    
    for (size_t i = 0; i < size; i++)  
        std::cout << arr[i] << " ";  
    std::cout << std::endl;  
}

int main() {
    int array[] = {9,8,7,6,5,4,3,2,1};
    int n = sizeof(array) / sizeof(array[0]);
    QuickSort(array, 0, n - 1);
    Print(array, n);
    return 0;
}