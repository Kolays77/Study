template<int N>
struct RandomInt {
    int operator()() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<int> uid(0, N);
        return uid(gen);
    }
};

template<typename T>
struct RandomReal {
    RandomReal(T f, T t) : from(f), to(t) {}
    T operator()() {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<T> dist(from, to);
        return dist(mt);
    }
private:
    T from;
    T to;
};