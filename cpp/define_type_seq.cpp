#include <iostream>
#include <fstream>

int DefineTypeSeq(const std::string& source) {
    const double EPS = 1e-12;
    double value;
    double prev;
    double d = 0, k = 1;
    std::ifstream in;
    bool is_ariphmetic = true;
    bool is_progressive = true;
    bool is_monotonic = true; 

    in.open("input.txt");

    if (!in.is_open()) return -1;
    if (!(in >> prev)) return -2;
    if (!(in >> value)) return -3;
    
    if (value == 0 || prev == 0) {
        is_progressive = false;
    } else {
        k = value / prev;
    }
    
    d = value - prev;    
    
    if ( prev != value) {
        is_monotonic = false;
    }
    
    while (in >> value) {
        if (is_progressive) {
            if ( value && prev ) {
                if (value / prev - k > EPS) {
                    is_progressive = false;
                }
            } else {
                is_progressive = false;
            }
        }

        if (value - prev - d > EPS) {
            is_ariphmetic = false;
        }

        if (prev != value) {
            is_monotonic = false;
        }
        prev = value;
    }

    if (is_monotonic) {
        return 3;
    } else if (is_progressive) {
        return 2;
    } else if (is_ariphmetic) {
        return 1;
    } else 
        return 0;
}


int main() {
    std::cout << DefineTypeSeq("input.txt") << std::endl;
}
    