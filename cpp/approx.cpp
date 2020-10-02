#include <iostream>
#include <cmath>
#include <iomanip>
const double PI = 3.1415926;
long double Sin(double x, const double EPS) {
    while (x > 2*PI) {
      x -= 2*PI;
    }

    while (x < -2*PI) {
      x += 2*PI;
    }

    long double value = x;
    long double cur_add = value;
    long double cur_factor;
    for(cur_factor = 3; std::abs(cur_add) >= EPS; cur_factor += 2) {
      cur_add *= (-x*x / (cur_factor * (cur_factor - 1)));
      value += cur_add;
    }
    return value;
}

long double Cos(double x, const double EPS) {
    while (x > 2*PI) {
      x -= 2*PI;
    }

    while (x < -2*PI) {
      x += 2*PI;
    }
    long double value = 1;
    long double cur_add = value;
    long double cur_factor;
    for(cur_factor = 2; std::abs(cur_add) >= EPS; cur_factor += 2) {
      cur_add *= (-x*x / (cur_factor * (cur_factor - 1)));
      value += cur_add;
    }
    return value;
}

long double Exp(double x, const double EPS) {
    long double value = 1;
    long double cur_add = value;
    long double cur_factor = 1;

    for (cur_factor = 1; std::abs(cur_add) > EPS; ++cur_factor) {
      cur_add = cur_add * x / cur_factor;
      value += cur_add;
    }
  return value;
}

long double Ln (double x, const double EPS) {
    const double e = 2.718281;
    int a = 0;
    while (x > 1) {
      ++a;
      x /= e;
    }
    
    long double value = 0;
    long double cur_add = x - 1;
    long double divider = 1;
    for (;std::abs(cur_add) > EPS; ++divider) {
      value += cur_add / divider;
      cur_add *= - (x-1);
    }
    return value + a;
}


long double Lg (double x, const double EPS) {
    int a = 0;
    long double temp = x;
    while (temp > 1) {
      ++a;
      temp /= 10;
    }
  
    long double value = Ln(temp,EPS);    
    double const ln10 = 2.3025871;
    return value / ln10 + a;
}

int main() {
    const double EPS = 1e-6;
    std::cout << "Type value x : ";
    double x;
    std::cin >> x;

    std::cout << "Choose func : sin, cos, exp, lg " << std::endl;
    std::string func;
    std::cin >> func;
    if (func == "cos") {
        std::cout << "std::cos : " << std::setprecision(10) << std::cos(x) << std::endl;
    std::cout << "My Cos : " << std::setprecision(10) << Cos(x, EPS) << std::endl;
    std::cout << '\n';
    }

    if (func == "sin") {
      std::cout << "std::sin : " << std::setprecision(10) << std::sin(x) << std::endl;
    std::cout << "My Sin : " << std::setprecision(10) << Sin(x, EPS) << std::endl;

    std::cout << '\n';

    }
    
    if (func == "exp") {
      std::cout << "std::exp : " << std::setprecision(10) << std::exp(x) << std::endl;
      std::cout << "My Exp : " << std::setprecision(10) << Exp(x, EPS) << std::endl;
      std::cout << '\n';
    }
    
    if (func == "lg") {
      std::cout << "std::log10 : " << std::setprecision(10) << std::log10(x) << std::endl;
      std::cout << "My lg : " << std::setprecision(10) << Lg(x, EPS) << std::endl;
    }
  
    return 0;
}
