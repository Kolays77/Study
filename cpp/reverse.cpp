#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <C:/Users/nimak/Git/Study/cpp/headers/print_collections.h>


#define DEBUG(x) std::cout << #x << " = " << (x) << std::endl;


int main() {
    unsigned shift = 2;    
    {
        std::vector<int> v = {1,2,4,5,6,7,8,9};
        std::cout << v << '\n';
        std::reverse(v.begin(),v.begin() + shift);
        std::reverse(v.begin() + shift, v.end());
        std::reverse(v.begin(), v.end());
        std::cout << v << '\n';
    }

    {
        std::vector<int> v = {1,2,4,5,6,7,8,9};
        std::cout << v << '\n';
        std::reverse(v.end() - shift, v.end());
        std::reverse(v.begin(), v.end()-shift);
        std::reverse(v.begin(), v.end());
        std::cout << v << '\n';
    }
    
    
}
