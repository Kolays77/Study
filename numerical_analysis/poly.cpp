#include <vector>
#include "headers/print_collections.h"
#include "/mnt/c/Users/nimak/Git/matplotlib-cpp/matplotlibcpp.h"
#include "headers/poly.h"

const double pi = 3.14159265359;
namespace plt = matplotlibcpp;

template <typename T>
Poly<T> CreateLagrangePoly(const std::vector<T>& xs, const std::vector<T>& ys) {
    const size_t deg = xs.size() - 1;
    Poly<T> poly, temp;
    T derivative = 1;
    for (size_t i = 0; i <= deg; ++i) {
        temp.Clear();
        temp[0] = ys[i];
        for (size_t j = 0; j <= deg; ++j) {
            if (i != j)
                temp *=  Poly<T>(std::vector<T>({-xs[j]/(xs[i] - xs[j]), 1.0/(xs[i] - xs[j])}));
        }
        poly += temp;
    }
    poly.Update();
    return poly;
}


double Newton2(double x, std::vector<double>& xs, std::vector<double>& ys) {
    double res = ys[0], F = 0, den = 1;
    double P = 1;
    int n = xs.size();
    int i, j, k;
    for (i = 1; i < n; i++) {
        P *= (x - xs[i]);
        F = 0;
        for (j = 0; j <= i; j++) {
            den = 1;
            for (k = 0; k <= i; k++) {
                if (k != j) den *= (xs[j] - xs[k]);
            }
            F += ys[j] / den;
        }
        F *= P;
        res += F;
    }
    return res;
}
 


// right answer is -1 + 6.5x -1.5x^2
void Test_1() {
    std::vector<double> xs = {1,2,3};
    std::vector<double> ys = {4,6,5};

    Poly<double> poly= CreateLagrangePoly(xs, ys);
    std::cout << "poly : " << poly << '\n';
    double x = 5;
    std::cout << "poly(" << x << ") = " << poly.At(x)  << '\n';
}

// right answer is 
void Test_2() {
    std::vector<double> xs = {0.1*pi, 0.2*pi, 0.3*pi, 0.4*pi};
    std::vector<double> ys;
    for(auto& it: xs) {
        ys.push_back(std::sin(it));
    }
    double x = pi / 4;
    Poly<double> poly= CreateLagrangePoly(xs, ys);
    std::cout << "poly : " << poly << '\n';

    std::cout << "poly(" << x << ") = " << poly.At(x)  << '\n';
    std::cout << "std::sin("  << x << ") = " << std::sin(x) << '\n';
}


// right answer is -0.384214 + 0.891912 x - 0.486794 x^2 + 0.11443 x^3
void Test_3() {
    std::vector<double> xs = {-2 ,-1, 0, 1};
    std::vector<double> ys;
    for(auto& it: xs) {
        ys.push_back(std::exp(it));
    }
    Poly<double> poly= CreateLagrangePoly(xs, ys);
    std::cout << "poly : " << poly << '\n';
    double x = -0.5;
    std::cout << "poly(" << x << ") = " << poly.At(x)  << '\n';
    std::cout << "std::exp("  << x << ") = " << std::exp(x) << '\n';
}

/*
int main1() {
    const double from = -4; 
    const double to = 4;
    const double dx = 0.1; 
    const size_t N = (to - from) / dx + 1;
    
    std::vector<double> points(N);
    points[0] = from;
    for (size_t i = 1; i < N; ++i) {   
        points[i] = points[i - 1] + dx;
    } 

    std::cout << "Approx EXP. Type number of points add type them"
    size_t n;
    std::cin >> n;

    std::vector<double> approx_points(n);
    std::vector<double> std_func_points(n);
    
    for (size_t i = 0; i < n; ++i) {
        std::cin >> approx_points[i];
        std_func_points[i] = std::exp(approx_points[i]);
        std::cout << approx_points[i] << " " << std_func_points << '\n';   
    }

    Poly<double> approx_poly = CreateLagrangePoly(x_poly, y_poly);
    std::cout << " Approx poly : " << approx_poly << std::endl;
    
    std::vector<double> (N); 
    std::vector<double> exp_y(N);
    
    for (size_t i = 0; i < N; ++i) {
        Y[i] = poly.At(xs[i]);
        exp_y[i] = std::exp(xs[i]);
    }

    plt::named_plot("std::exp(x)", xs, exp_y);
    plt::named_plot("my exp(x)", xs, Y);
    plt::xlim(from, to); // Set x-axis to interval [0,1000000]
    plt::title("Test");
    plt::legend();
    plt::show();
}
*/

int main() { 
    std::cout << "Number of points = ";
    int n;
    std::cin >> n;
    std::vector<double> approx_points(n);
    std::vector<double> std_func_points(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> approx_points[i];
        std_func_points[i] = std::exp(approx_points[i]);
        std::cout << approx_points[i] << " " << std_func_points[i] << '\n';   
    }

    double x;
    std::cout << "TYPE X = ";
    std::cin >> x;
    std::cout << Newton2(x, approx_points, std_func_points);
}