#include <random>

struct RandomInt {
    static int gen(int from, int to){
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<int> uid(from, to);
        return uid(gen);
    }
};

struct RandomReal {
    static double gen(double from, double to) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> urd(from, to);
        return urd(gen);
    }
};
