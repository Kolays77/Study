#include <iostream>
#include <iomanip>

void Print(double** matrix, size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            std::cout << std::setw(4) << std::left << matrix[i][j] << " ";
        }
        std::cout << "\n";
    } 
}
// 1
void Transpose(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}
// 2 + 3
void Mod(double** matrix, int n) {
    double temp;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            temp = (matrix[i][j] - matrix[j][i]) / 2;

            matrix[i][j] = matrix[j][i] = temp;
        }
    }
}
// 4
void MoveRows(double** matrix, int k, int j, int n) {
    for (int i = 0; i < n; i++) {
        std::swap(matrix[k][i], matrix[i][k]);
    }
}

int main() {
    size_t n;
    std::cin >> n;
    double** matrix = new double*[n];

    for (size_t i = 0; i < n; i++) {
        matrix[i] = new double[n];
        for (size_t j = 0; j < n; j++) {
            matrix[i][j] = n*i + j + 1;
        }
    }

    
    Print(matrix, n);
    //

    Mod(matrix,n);
    
    //
    std::cout << std::endl;
    Print(matrix, n);
    
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete [] matrix;
    return 0;
}