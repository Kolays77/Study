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
  while (xs[i] != point) {
    ++i;
  }
  std::cout << "left first derivative : " << (ys[i] - ys[i -1]) / (xs[i] - xs[i - 1]) << "\n";
  std::cout << "right first derivative : " << (ys[i + 1] - ys[i]) / (xs[i + 1] - xs[i]) << "\n";
  std::cout << "centr first derivative : " << (ys[i + 1] - ys[i - 1]) / (2*(xs[i + 1] - xs[i - 1])) << "\n";

std::cout << "centr double derivative : " << (ys[i + 1] - 2*ys[i] + ys[i -1]) /( (xs[i + 1] - xs[i - 1])*(xs[i + 1] - xs[i - 1])) << "\n";

}
