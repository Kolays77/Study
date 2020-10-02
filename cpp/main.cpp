#include <iostream>
#include <list>
template<class It>
size_t max_increasing_len(It p, It q)
{
    size_t max_len = 0;
    bool entry = false;
    for (; p != q;) {
        entry = true;
        if (*p < *(++p)) {
            ++max_len;
        } else {
            max_len = 1;
        }
    }
    if (entry) {
        return max_len;
    } else {
        return 1;
    }
}



int main () {
    std::list<int> const l1 = {7};
   size_t len1 = max_increasing_len(l1.begin(), l1.end()); // 4, соответствует подотрезку 1,2,3,4
    std::cout << len1 << std::endl;
    std::list<int> const l2 = {-3,-2,-1,0,0,1,2,3,4,5};
    size_t len2 = max_increasing_len(l2.begin(), l2.end()); // 6, соответствует подотрезку 0,1,2,3,4,5
    std::cout << len2 << std::endl;
    return 0;
}