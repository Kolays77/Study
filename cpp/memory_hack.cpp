#include <string>
#include <iostream>
#include <cstring>

struct Cls {
    Cls(char _c, double _d, int _i) : c(_c), d(_d), i(_i) {};
private:
    char c;
    double d;
    int i;
};

struct ClsPubl
{
   ClsPubl(char _c, double _d, int _i) : c(_c), d(_d), i(_i) {};
public: 
    char c;
    double d;
    int i;
};



char &get_c2(Cls &cls) {
    return *(char*)(&cls); 
}

double &get_d2(Cls &cls) {
    return *((double *)&cls+1); 
}

int &get_i2(Cls &cls) {
    return *((int *)&cls+ 4); 
}

char &get_c(Cls &cls) {
    void* voidptr = static_cast<void*>(&cls); 
    struct ClsPubl * p = static_cast<ClsPubl*>(voidptr); 
    return p->c; 
}

double &get_d(Cls &cls) {
    void* voidptr = static_cast<void*>(&cls); 
    struct ClsPubl * p = static_cast<ClsPubl*>(voidptr); 
    return p->d; 
}


int &get_i(Cls &cls) {
    void* voidptr = static_cast<void*>(&cls); 
    struct ClsPubl * p = static_cast<ClsPubl*>(voidptr); 
    return p->i; 
}

int main() {    
    Cls c('c',2.2,3);
    std::cout << get_c2(c) << '\n';
    std::cout << get_d2(c) << '\n';
    std::cout << get_i2(c) << '\n';
}