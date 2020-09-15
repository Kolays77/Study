#include <iostream>
#include <fstream>

template <int N>
class ModNumber {
    int value;
public:
    ModNumber(int val) : value((val % N + N) % N) {}

    ModNumber(const ModNumber& n) {
        value = n.GetValue();
    }

    ModNumber* operator=(ModNumber& n) {
        if (&n != this) {
            value = n.GetValue();
        }
        return this;
    }

    int GetValue() const {
        return value;
    }  
};


template<int N>
std::ostream& operator<<(std::ostream& out, ModNumber<N> n) {
    return out << n.GetValue();
}

template<int N>
ModNumber<N> operator+(ModNumber<N> lhs, ModNumber<N> rhs) {
    return ModNumber<N>(lhs.GetValue() + rhs.GetValue());
} 

template<int N>
ModNumber<N> operator-(ModNumber<N> lhs, ModNumber<N> rhs) {
    return ModNumber<N>(lhs.GetValue() - rhs.GetValue());
} 

template<int N>
ModNumber<N> operator*(int lhs, ModNumber<N> rhs) {
    return ModNumber<N>(lhs * rhs.GetValue());
} 


template<int N>
ModNumber<N> operator*(ModNumber<N> lhs, int rhs) {
    return ModNumber<N>(lhs.GetValue() * rhs);
} 


template<int N>
ModNumber<N> operator*(ModNumber<N> lhs, ModNumber<N> rhs) {
    return ModNumber<N>(lhs.GetValue() * rhs.GetValue());
} 

template<int N>
ModNumber<N> operator/(ModNumber<N> lhs, ModNumber<N> rhs) {
    return ModNumber<N>(lhs.GetValue() * rhs.GetValue());
} 

template<int N>
ModNumber<N> Inverse(const ModNumber<N>& number ) {
    if (number.GetValue() == 1) {
        return ModNumber<N>(number);
    } 
    if (N == 2) {
        return ModNumber<N>(0);
    }

    for (int i = 2; i < N; ++i) {
        ModNumber<N> n = number * i;
        if (n.GetValue() == 1) {
            return ModNumber<N>(i);
        }
    }
    return ModNumber<N>(0);
}

int main () {
    ModNumber<100> a = 33;
    ModNumber<100> b = Inverse(a);
    std::cout << b << std::endl; 
    std::cout << a * b << '\n';
    return 0;
}
