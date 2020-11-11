#include <iostream>
#include <vector>

double Newton(double x, const std::vector<double>& xs, const std::vector<double>& ys) {
    size_t n = xs.size();
    double ans = ys[0];
    double P = 1;     
    for (size_t i = 0; i < n; ++i) {
        double temp = 1;
        P *= (x - xs[i]);
        
        for (size_t j = 0; j <= i; ++j) {
            double 
            for (size_t k = 0; k < n; ++k) {

            }   

        }
    }
    return ans;
}


int main() {
    double x = sqr(2);
    std::cout << x << std::endl;
}