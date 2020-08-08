#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <cassert>

using namespace std;
template<class T>
class Matrix {
private:
  int num_rows_;
  int num_columns_;
public:
  vector<vector<T>> elements_;

public:
  Matrix() {
    num_rows_ = 0;
    num_columns_ = 0;
  }
  
  
  Matrix(vector<vector<T>> m) : elements_(m), 
                                        num_rows_(m.size()),
                                        num_columns_(m[0].size()) {}
  
  
  
  Matrix(const Matrix<T>& matrix) : elements_(matrix.elements_), 
                                    num_rows_(matrix.GetNumRows()),
                                    num_columns_(matrix.GetNumColumns()) {}
  Matrix(int num_rows, int num_columns) {
    Reset(num_rows, num_columns);
  }
    
  void Set(vector<vector<T>> m){
    elements_ = m;
    num_rows_ = m.size();
    num_columns_ = m[0].size();
  }
  void Reset(int num_rows, int num_columns) {
    if (num_rows < 0) {
      throw out_of_range("num_rows must be >= 0");
    }
    if (num_columns < 0) {
      throw out_of_range("num_columns must be >= 0");
    }
    if (num_rows == 0 || num_columns == 0) {
      num_rows = num_columns = 0;
    }

    num_rows_ = num_rows;
    num_columns_ = num_columns;
    elements_.assign(num_rows, vector<T>(num_columns, 0));
  }

  T& At(int row, int column) {
    return elements_.at(row).at(column);
  }

  T At(int row, int column) const {
    return elements_.at(row).at(column);
  }

  T GetNumRows() const {
    return num_rows_;
  }

  T GetNumColumns() const {
    return num_columns_;
  }

  vector<T>& operator[](int index){
    return elements_[index];
  }
  
  void operator=(const vector<vector<T>> m){
    num_rows_ = m.size();
    num_columns_ = m[0].size();
    elements_ = m;
  }
  
  
  
};
template <typename T>
bool operator==(const Matrix<T>& one, const Matrix<T>& two) {
  if (one.GetNumRows() != two.GetNumRows()) {
    return false;
  }

  if (one.GetNumColumns() != two.GetNumColumns()) {
    return false;
  }

  for (int row = 0; row < one.GetNumRows(); ++row) {
    for (int column = 0; column < one.GetNumColumns(); ++column) {
      if (one.At(row, column) != two.At(row, column)) {
        return false;
      }
    }
  }

  return true;
}

template <typename T>
Matrix<T> operator+(const Matrix<T>& one, const Matrix<T>& two) {
  if (one.GetNumRows() != two.GetNumRows()) {
    throw invalid_argument("Mismatched number of rows");
  }

  if (one.GetNumColumns() != two.GetNumColumns()) {
    throw invalid_argument("Mismatched number of columns");
  }

  Matrix<T> result(one.GetNumRows(), one.GetNumColumns());
  for (int row = 0; row < result.GetNumRows(); ++row) {
    for (int column = 0; column < result.GetNumColumns(); ++column) {
      result.At(row, column) = one.At(row, column) + two.At(row, column);
    }
  }

  return result;
}

template <typename T>
istream& operator>>(istream& in, Matrix<T>& matrix) {
  int num_rows, num_columns;
  in >> num_rows >> num_columns;

  matrix.Reset(num_rows, num_columns);
  for (int row = 0; row < num_rows; ++row) {
    for (int column = 0; column < num_columns; ++column) {
      in >> matrix.At(row, column);
    }
  }

  return in;
}


template <typename T>
ostream& operator<<(ostream& out, const Matrix<T>& matrix) {
  //out << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;
  for (int row = 0; row < matrix.GetNumRows(); ++row) {
    for (int column = 0; column < matrix.GetNumColumns(); ++column) {
      if (column > 0) {
        out << " ";
      }
      out << matrix.At(row, column);
    }
    out << endl;
  }

  return out;
}

template <typename T>
Matrix<T> Multiply(const Matrix<T>& left, const Matrix<T>& right){
    int n = left.GetNumRows();
    int k = left.GetNumColumns();
    int m = right.GetNumColumns();
    if(left.GetNumColumns() != right.GetNumRows()){
        throw invalid_argument("Multiply Error left col != right rows");
    }
 
    Matrix<T> result(n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int t = 0; t < k; t++){      
                result.At(i,j) += left.At(i,t) * right.At(t,j); 
            }
        }
    }
    
    return result; 
    
    
}   

