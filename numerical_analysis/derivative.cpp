#include <iostream>
#include <vector>

double right_derivative(int i, std::vector<double>& ys, double h) {
  if (i < ys.size() - 1) {
    return (ys[i + 1] - ys[i]) / h;
  }
  return 0;
}


int main() {
  int n = 5;
  std::cout << "N = " << n << std::endl;
  double h = 1;
  int i = 2;
  std::cout << "i = " << i << std::endl;
  std::vector<double> xs = {-1, 0, 1, 2, 3};
  std::vector<double> ys = {-0.5, 0.0, 0.5, 0.86603, 1.0}; 
  
  for (int index = 0; index < n; ++index) {
    std:: cout << right_derivative(index, ys, h) << " ";
  }
  std::cout << '\n';
  double y_0_right = (ys[i + 1] - ys[i]) / h;
  double y_1_right = (ys[i] - ys[i - 1]) / h;

  std::cout << "y_0_right  " << y_0_right << std::endl;
  std::cout << "y_1_right  " << y_1_right << std::endl;
  double res = (y_0_right - y_1_right) / h;
  std::cout << "res : " << res << std::endl;
  //std::cout << "left first derivative for x = : "<< xs[i] << " : " << (ys[i] - ys[i -1]) / h << "\n";
  //std::cout << "right first derivative for x =  " << xs[i] << " : " << (ys[i + 1] - ys[i]) / h << "\n";
  //std::cout << "centr first derivative for x = " << xs[i] << " : " << (ys[i + 1] - ys[i - 1]) / (2*h) << "\n";
  //std::cout << "centr double derivative for x =  " << xs[i] << " : " << (ys[i + 1] - 2*ys[i] + ys[i -1]) / (h*h) << "\n";
}
