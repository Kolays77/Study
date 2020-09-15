#include <vector>
#include <random>
#include "headers/print_collections.h"
#include "/mnt/c/Users/nimak/Git/matplotlib-cpp/matplotlibcpp.h"


const double pi = 3.14159265359;
const double EPS = 1e-6;
// repr: [1,2,3,4] -> 1 + 2*x + 3*x^2 + 4*x^3
template <typename T>
class Poly {
    std::vector<T> coef_;
    size_t deg_;
public:

    void Update(){
        while((coef_.back() == 0 || coef_.back() < EPS ) && deg_){
            coef_.pop_back();
            --deg_;
        }
    }

    T At(const T& value) {
        T res = coef_[0];
        T pow = 1;
        for (size_t i = 1; i <= deg_; ++i) {
            pow *= value;
            res += pow*coef_[i];
        }
        return res;
    }

    Poly() : coef_(1,0), deg_(0) {}

    explicit Poly(size_t deg, T value = 0) : coef_(deg + 1, value), deg_(deg) {}

    Poly(std::vector<T> coef) {
        coef_ = std::move(coef);
        while (*(coef_.end() - 1) == 0) {
            coef_.pop_back();
        }
        deg_ = (coef_.size() - 1);
    }

    size_t GetDeg() const {
        return deg_;
    }

    const T operator[](size_t index) const{
        if(index > deg_){
            return 0;
        }
        return coef_[index];
    }

    T& operator[](size_t index) {

        return coef_[index];
    }

    Poly& operator=(const std::vector<T>& coef) {
        coef_ = coef;
        deg_ = (coef_.size() - 1);
        return *this;
    }

    const std::vector<T> GetCoef() const {
        return coef_;
    }

    void Clear() {
        coef_.clear();
        coef_.push_back((T)0);
        deg_ = 0;
    }


    Poly& operator*=(const Poly & rhs){
        Poly temp(deg_ + rhs.GetDeg());
        for(size_t i = 0; i <= deg_ ; ++i){
            for(size_t j = 0; j <= rhs.GetDeg() ; ++j){
                temp[i+j] += (coef_[i]*rhs[j]);
            }
        }
        *this = temp;
        return *this;
    }

    Poly& operator+=(const Poly & rhs){
        Poly temp(std::max(deg_, rhs.GetDeg()));
        for(size_t i = 0; i <= temp.GetDeg() ; ++i){
            temp[i] += (coef_[i] + rhs[i]);
        }
        *this = temp;
        return *this;
    }


    Poly<T>& operator/=(T value){
        for(size_t i = 0; i <= deg_ ; ++i){
            coef_[i] = coef_[i] / value;
        }
        return *this;
    }

};

template <typename T>
Poly<T> operator+(const Poly<T>& p1, const Poly<T>& p2) {
    Poly<T> p(std::max(p1.GetDeg(), p2.GetDeg()));
    for (size_t i = 0; i <= p.GetDeg(); ++i) {
        p[i] = p1[i] + p2[i];
    }
    return p;
}

template <typename T>
Poly<T> operator*(const Poly<T> & p1, const Poly<T> & p2){
    size_t lhs_deg = p1.GetDeg();
    size_t rhs_deg = p2.GetDeg();

    Poly<T> ans(lhs_deg + rhs_deg);
    for(size_t i = 0; i <= lhs_deg ; ++i){
        for(size_t j = 0; j <= rhs_deg ; ++j){
            ans[i+j] += (p1[i]*p2[j]);
        }
    }
    return ans;
}

template <typename T>
Poly<T> operator*(const Poly<T> & p, T value){
    if (value == 0)
        p.Clear();

    size_t deg = p.GetDeg();
    Poly<T> ans(deg);
    for(size_t i = 0; i <= deg ; ++i){
        ans[i] = p[i] * value;
    }
    return ans;
}

template <typename T>
Poly<T> operator/(const Poly<T> & p, const T& value){
    size_t deg = p.GetDeg();
    Poly<T> ans(deg);
    for(size_t i = 0; i <= deg ; ++i){
        ans[i] = p[i] / value;
    }
    return ans;
}



template <typename T>
std::ostream& operator<<(std::ostream& out, const Poly<T>& p) {
    return out << p.GetCoef();
}



template <typename T>
Poly<T> CreateNewTonePoly(const std::vector<T>& xs, const std::vector<T>& ys) {
    Poly<T> res(1,ys[0]);
    Poly<T> F (1,0); 
    double temp = 1, n = xs.size();
    for (size_t i = 1; i < n; ++i) {
        F.Clear();
        F[0] = 0;
        for (size_t j = 0; j <= i; ++j) {
            temp = 1;
            for (size_t k = 0; k <= i; ++k) {
                if (k != j) temp *= (xs[j] - xs[k]);
            }
            F[0] += ys[j] / temp;
        }
        for (size_t k = 0; k < i; ++k) {
            F *= Poly<T>(std::vector<T>({-xs[k], 1}));
        }
        res += F;
    }
    return res;
}


double Newton2(double x, std::vector<double>& xs, std::vector<double>& ys)
        {
            double res = ys[0], F = 0, den = 1;
            int n = xs.size();
            int i, j, k;
            for (i = 1; i < n; i++)
            {
                F = 0;
                for (j = 0; j <= i; j++)
                {
                    den = 1;
                    for (k = 0; k <= i; k++)
                    {
                        if (k != j) den *= (xs[j] - xs[k]);
                    }
                    F += ys[j] / den;
                }
                for (k = 0; k < i; k++) F *= (x - xs[k]);
                res += F;
            }
            return res;
        }
 



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

namespace plt = matplotlibcpp;


int main() {
    const double from = -10; 
    const double to = 10;
    const double dx = 0.1; 
    const size_t N = (to - from) / dx + 1;

    double temp = from;
    std::vector<double> xs(N);

    for (size_t i = 0; i < N; ++i) {   
        xs[i] = temp;
        temp += dx;
    } 

    std::vector<double> sin(N);
    std::vector<double> cos(N);
    std::vector<double> tan(N);
    std::vector<double> cotan(N);
    
    for (size_t i = 0; i < N; ++i) {   
        sin[i] = std::sin(xs[i]);
        cos[i] = std::cos(xs[i]);
        tan[i] = std::tan(xs[i]);
    } 

    
    plt::named_plot("sin(x)", xs, sin);
    plt::named_plot("cos(x)", xs, cos);


    plt::xlim(from, to); // Set x-axis to interval [0,1000000]
    plt::title("Test");
    plt::legend();
    //plt::save("basic.png");
    plt::show();
}
