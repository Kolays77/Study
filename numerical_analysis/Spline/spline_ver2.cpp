#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Spline{
    double a;
    double b;
    double c;
    double d;
    double x;
};

std::vector<Spline> BuildSpline(std::vector<double> &x, std::vector<double> &y) {
    int n = x.size()-1;
    std::vector<double> a;
    a.insert(a.begin(), y.begin(), y.end());
    std::vector<double> b(n);
    std::vector<double> d(n);
    std::vector<double> h;

    for(int i = 0; i < n; ++i)
        h.push_back(x[i+1]-x[i]);

    std::vector<double> alpha;
    alpha.push_back(0);
    for(int i = 1; i < n; ++i)
        alpha.push_back( 3*(a[i+1]-a[i])/h[i] - 3*(a[i]-a[i-1])/h[i-1] );

    std::vector<double> c(n+1);
    std::vector<double> l(n+1);
    std::vector<double> mu(n+1);
    std::vector<double> z(n+1);
    l[0] = 1;
    mu[0] = 0;
    z[0] = 0;

    for(int i = 1; i < n; ++i) {
        l[i] = 2 *(x[i+1]-x[i-1])-h[i-1]*mu[i-1];
        mu[i] = h[i]/l[i];
        z[i] = (alpha[i]-h[i-1]*z[i-1])/l[i];
    }

    l[n] = 1;
    z[n] = 0;
    c[n] = 0;

    for(int j = n-1; j >= 0; --j) {
        c[j] = z [j] - mu[j] * c[j+1];
        b[j] = (a[j+1]-a[j])/h[j]-h[j]*(c[j+1]+2*c[j])/3;
        d[j] = (c[j+1]-c[j])/3/h[j];
    }

    std::vector<Spline> output_set(n);
    for(int i = 0; i < n; ++i) {
        output_set[i].a = a[i];
        output_set[i].b = b[i];
        output_set[i].c = c[i];
        output_set[i].d = d[i];
        output_set[i].x = x[i];
    }
    return output_set;
}

void print(Spline cs, ) {
    std::cout << cs.a << "\t" << cs.b << "\t" << cs.c << "\t" << cs.d << std::endl;
}


int main() {
    std::vector<double> xxx = {0.1, 0.5, 0.9, 1.3, 1.7};
    std::vector<double> yyy = {-2.3026, -0.69315, -0.10536, 0.26236, 0.53063};
    std::vector<Spline> cs = BuildSpline(x, y);
    for(int i = 0; i < cs.size(); ++i) {
        print(cs[i]);
    }
    return 0;
}