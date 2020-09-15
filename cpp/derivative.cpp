#include <iostream>
#include <vector>


int main2() {
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

    double h = xs[1] - xs[0];
    std::cout << "left first derivative : " << (ys[i] - ys[i -1]) / h << "\n";
    std::cout << "right first derivative : " << (ys[i + 1] - ys[i]) / h << "\n";
    std::cout << "centr first derivative : " << (ys[i + 1] - ys[i - 1]) / 2*h << "\n";
    std::cout << "centr double derivative : " << (ys[i + 1] - 2*ys[i] + ys[i -1]) / h*h << "\n";
    return 0;
}

int main() {
    std::vector<double> xs = {1., 0, 1, 2, 3};
    std::vector<double> ys = {-0.5, 0, 0.5, 0.86603, 1.0}; 
    int n = xs.size();
    double point = 2.0;
    std::cout << "Point x* = 2.0" << '\n';
    int i = 0;
    while (xs[i] != point) ++i;
    double h = xs[1] - xs[0];
    std::cout << "left first derivative : " << (ys[i] - ys[i -1]) / h << "\n";
    std::cout << "right first derivative : " << (ys[i + 1] - ys[i]) / h << "\n";
    std::cout << "centr first derivative : " << (ys[i + 1] - ys[i - 1]) / 2*h << "\n";
    std::cout << "centr double derivative : " << (ys[i + 1] - 2*ys[i] + ys[i -1]) / h*h << "\n";
    return 0;
}