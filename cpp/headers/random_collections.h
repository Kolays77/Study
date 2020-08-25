#include <random>
#include <chrono>
#include <vector>

namespace Random {   
    template <typename T>
    T* Array(size_t n, T from, T to) {
        T* arr = new T[n];
        std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<> dist(from, to);  
        for (size_t i = 0; i < n; i++) {
            arr[i] = (T)dist(rng);
        }
        return arr;
    }

    template <typename T>
    std::vector<T> Vector(size_t n, T from, T to) {
        std::vector<T> v(n);
        std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<> dist(from, to);  
        for (size_t i = 0; i < n; i++) {
            v[i] = dist(rng);
        }
        return v;
    }
}
