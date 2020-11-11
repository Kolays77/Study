#include <string>
#include <iostream>
#include <bitset>

int main(){
	std::string alpha_bit_string = "aBaaBBaB";
    std::bitset<8> number(alpha_bit_string, 0, alpha_bit_string.size(),
                      'a', 'B');         // [0,1,0,0,1,1,0,1]
	std::cout << number;
}
