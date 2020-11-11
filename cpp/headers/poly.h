#pragma once
#include <vector>
#include <iostream>
#include <initializer_list>
template<typename Iterator>
std::ostream& PrintIter(std::ostream& os, Iterator begin, Iterator end) {
    for (auto it = begin; it != end; os << *it++)
        if (it != begin) os << ", ";
    return os;
}


template<class T>
std::ostream& PrintVec(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    return PrintIter(os, vec.begin(), vec.end()) << "]";
}


const double EPS = 1e-9;
// repr: [1,2,3,4] -> 1 + 2*x + 3*x^2 + 4*x^3
template <typename T = double >
class Poly {
    std::vector<T> coef_;
    size_t deg_;
public:
    Poly();
    explicit Poly(size_t deg, T value = 0);
    Poly(Poly& p); 
    Poly(std::vector<T> coef);
    Poly(T value); 

    size_t GetDeg() const;
    const std::vector<T>& GetCoef() const;
    
    void Clear();
    void Update();

    Poly Derivative() const;

    T At(const T& value);
    std::vector<T> At(const std::vector<T>& points);
    
    const T operator[](size_t index) const;
    T& operator[](size_t index);    

    Poly& operator=(const Poly& rhs);

    Poly& operator*=(const Poly& rhs);
    Poly& operator+=(const Poly& rhs);
    Poly& operator/=(T value);
};

template <typename T>
Poly<T> operator+(const Poly<T>& p1, const Poly<T>& p2);

template <typename T>
Poly<T> operator*(const Poly<T>& p1, const Poly<T>& p2);

template <typename T>
Poly<T> operator*(const Poly<T>& p, T value);

template <typename T>
Poly<T> operator/(const Poly<T>& p, const T& value);

template <typename T>
std::ostream& operator<<(std::ostream& out, const Poly<T>& p);

template <typename T>
bool operator==(const Poly<T>& p1, const Poly<T>& p2);


/////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////

template <typename T>
Poly<T>::Poly() : coef_(1,0), deg_(0) {}

template <typename T>
Poly<T>::Poly(Poly<T>& p) : coef_(p.GetCoef()), deg_(p.GetDeg()) {}



template <typename T>
Poly<T>::Poly(size_t deg, T value) : coef_(deg + 1, value), deg_(deg) {}


template <typename T>
Poly<T>::Poly(std::vector<T> coef) {
    coef_ = std::move(coef);
    deg_ = (coef_.size() - 1);
    Update();
}


template <typename T>
Poly<T>::Poly(T value) {
    if (std::abs(value) < EPS) {
        value = 0;
    }
    coef_ = std::vector<T>(1, value);
    deg_ = 0;
}


template <typename T>
size_t Poly<T>::GetDeg() const {
    return deg_;
}


template <typename T>
const std::vector<T>& Poly<T>::GetCoef() const {
    return coef_;
}


template <typename T>
void Poly<T>::Clear() {
    coef_.clear();
    coef_.push_back((T)0);
    deg_ = 0;
}


template <typename T>
void Poly<T>::Update(){
    while((std::abs(coef_.back()) < EPS ) && deg_){
        coef_.pop_back();
        --deg_;
    }
}


template <typename T>
Poly<T> Poly<T>::Derivative() const {
    /// from x + x^2 [0 1 1] -->  1 + 2x [1 2]
    if (this->GetDeg() == 0) {
        
        return Poly<T>(std::vector<T>(1,0));
    }
    size_t deg = this->GetDeg();
    std::vector<T> tmp(deg, 0); 
    
    for (size_t i = 1; i <= deg; ++i) {
        
        tmp[i - 1] = this->operator[](i)  * (double)i; 
        
    }

    return Poly<T>(std::vector<T>(tmp.begin(), tmp.end()));
}


template <typename T>
T Poly<T>::At(const T& point) {
    T value = coef_[0];
    T pow = 1;
    for (size_t i = 1; i <= deg_; ++i) {
        pow *= point;
        value += pow*coef_[i];
    }
    return value;
}


template <typename T>
std::vector<T> Poly<T>::At(const std::vector<T>& points){
    std::vector<T> values(points.size());
    const size_t len = points.size();
    for (size_t i = 0; i < len; ++i) {
        values[i] = At(points[i]);
    }
    return values;
}


template <typename T>
const T Poly<T>::operator[](size_t index) const{
    if(index > deg_){
        return 0;
    }
    return coef_[index];
}


template <typename T>
T& Poly<T>::operator[](size_t index) {
    return coef_[index];
}


template <typename T>
Poly<T>& Poly<T>::operator=(const Poly<T>& rhs) {
    coef_ = rhs.GetCoef();
    deg_ = (coef_.size() - 1);
    return *this;
}

   
template <typename T>
Poly<T>& Poly<T>::operator*=(const Poly<T>& rhs){
    Poly temp(deg_ + rhs.GetDeg());
    for(size_t i = 0; i <= deg_ ; ++i){
        for(size_t j = 0; j <= rhs.GetDeg() ; ++j){
            temp[i+j] += (coef_[i]*rhs[j]);
        }
    }
    *this = temp;
    return *this;
}


template <typename T>
Poly<T>& Poly<T>::operator+=(const Poly<T> & rhs){
    Poly temp(std::max(deg_, rhs.GetDeg()));
    for(size_t i = 0; i <= temp.GetDeg() ; ++i){
        temp[i] += (coef_[i] + rhs[i]);
    }
    *this = temp;
    return *this;
}


template <typename T>
Poly<T>& Poly<T>::operator/=(T value){
    for(size_t i = 0; i <= deg_ ; ++i){
        coef_[i] = coef_[i] / value;
    }
    return *this;
}


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
    return PrintVec(out, p.GetCoef());
}


template <typename T>
bool operator==(const Poly<T>& p1, const Poly<T>& p2) {
    return p1.GetCoef() == p2.GetCoef(); 
}
