struct Number {
    Number(int _x) : x(_x) {}
    int x;
};


struct BigInt : Number {
    BigInt(int x) : Number(x) {}
};

struct String {
    explicit String(char const * s);
};

int main() {
    BigInt c = 100500;
    
}