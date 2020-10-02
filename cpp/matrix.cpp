#include <iostream>
#include <iomanip>
#include <cmath>

void Print(double** matrix, size_t m, size_t n) {
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            std::cout << std::setw(4) << std::left << matrix[i][j] << " ";
        }
        std::cout << "\n";
    } 
}
// 1 Only NxN matrixes
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
void SwapRows(double** matrix, int k, int j, int n, int m) {
    for (int i = 0; i < n; i++) {
        std::swap(matrix[k][i], matrix[j][i]);
    }
}
// 5
void SwapCols(double** matrix, int k, int j, int n, int m) {
    for (int i = 0; i < m; i++) {
        std::swap(matrix[i][k], matrix[i][j]);
    }
}

// 6 
void AddRows(double** matrix, size_t m, size_t n, int k, int j, double b) {
    for (int i = 0; i < m; i++) {
        matrix[k][i] += matrix[j][i]*b;
    }
}

void AddCols(double** matrix, size_t m, size_t n, int k, int j, double b) {
    for (int i = 0; i < m; i++) {
        matrix[i][k] += matrix[i][j]*b; 
    }
}


double** Init(size_t m, size_t n) {
    double** matrix = new double*[m];
    for (size_t i = 0; i < n; i++) {
        matrix[i] = new double[n];
        for (size_t j = 0; j < n; j++) {
            matrix[i][j] = n*i + j + 1;
        }
    }
    return matrix;
}

void DeleteMatrix(double** matrix, size_t m, size_t n) {
    for (int i = 0; i < m; i++) {
        delete[] matrix[i];
    }
    delete [] matrix;
 
    matrix = nullptr;
}

int main() {

    size_t m, n;
    std::cin >> m >> n;
    double** matrix = Init(m,n);
    Print(matrix, m, n);
    
    //
    AddRows(matrix, m, n, 0, 1, 2);
    //

    std::cout << std::endl;
    Print(matrix, m, n);
    DeleteMatrix(matrix, m, n); 
    return 0;
}