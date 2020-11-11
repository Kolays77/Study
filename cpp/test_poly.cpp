#include <vector>

#include "headers/print_collections.h"
#include "headers/poly.h"

int main() {
    Poly<double> p1({1,3,5,5,5});
    Poly<double> p2({5,5});
    
    p2 = p1;
    std::cout << p2;
    return 0;
}   