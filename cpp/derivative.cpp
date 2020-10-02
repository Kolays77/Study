#include <iostream>
#include <vector>


int main() {
  std::cout << "N = ";
  int n;
  std::cin >> n;

  std::vector<double> xs;
  std::vector<double> ys; 
  double x, y;
  for (int i = 0; i < n; ++i) {
    std::cout << "Type x_" << i << ", y_" << i << " = ";
    std::cin >> x >> y;
    xs.push_back(x);
    ys.push_back(y);
  }
  double point;
  std::cout << "Point x* = ";
  std::cin >> point; 

  int i = 0;
  while (xs[i] != point) { // узнаем номер x* 
    ++i;
  }
  double h = (xs[i] - xs[i - 1]);
  std::cout << "left first derivative : " << (ys[i] - ys[i -1]) / h << "\n";
  std::cout << "right first derivative : " << (ys[i + 1] - ys[i]) / h << "\n";
  std::cout << "centr first derivative : " << (ys[i + 1] - ys[i - 1]) / (2*h) << "\n";
  std::cout << "centr double derivative : " << (ys[i + 1] - 2*ys[i] + ys[i -1]) / (h*h)) << "\n";
}
