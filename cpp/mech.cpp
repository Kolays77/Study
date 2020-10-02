#include <iostream>
#include <vector>
#include <cmath>
#include "/mnt/c/Users/nimak/Git/matplotlib-cpp/matplotlibcpp.h"

namespace plt = matplotlibcpp;

double Cos(double t) {
    return std::pow(std::cos(t),3);
}

double Sin(double t) {
    return std::pow(std::sin(t),3);
}

int main() {
    const double from = -3.14159265359; 
    const double to = 3.14159265359;
    const double dx = 0.01; 
    const size_t N = (to - from) / dx + 1;
    const double l = 2;
    std::vector<double> points(N);
    double temp = from;
    
    for (size_t i = 0; i < N; ++i) {
        points[i] = temp;
        temp += dx;
    }
    
    std::vector<double> b_x(N);
    std::vector<double> b_y(N);

    for (size_t i = 0; i < N; ++i) {
        b_x[i]=  3*std::cos(points[i])*l;
        b_y[i] = -std::sin(points[i])*l;
    }

    plt::named_plot("func", b_x, b_y);
    
    plt::title("Test");
    plt::legend();
    plt::show();
    return 0;
}