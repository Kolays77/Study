#include "headers/random_collections.h"
#include "headers/print_collections.h"
#include <iostream>
#include <cstring>
const char *strstr_ (const char *string1, const char *string2) {
    size_t len1 = strlen(string1);
    size_t len2 = strlen(string2);
    if (len2 > len1) {
        return nullptr;
    }
    for (size_t i = 0; i < len1; i++) {
        bool st = true;
        for (size_t j = 0; j < len2 && i + j <= len1; j++) {
            if (string1[i + j] != string2[j]) {
                st = false;
                break;  
            }
        } 
        if (st)
            return &string1[i];
    }
    return nullptr;
}

void strcpy_(const char* source, char* target) {
    size_t len = strlen(source);
    char* temp = new char[len + 1];
    while ((*target++ = *source++));
    target = temp - len;
}


const char *strrchr_ (const char *string, int ch) {
    if (ch < 0) {
        return nullptr;
    }

    size_t len = strlen(string);

    for (size_t i = 0; i < len; i++) {
        if (string[i] == ch) {
            std::cout << "YES";
        }
    }
    return &string[2];
}

int main() {
    const char* source = "asdas";
    char* ans;
    strcpy_(source, ans);
    std::cout << strlen(ans);
    strrchr_(source, 65);
    delete [] ans;
    return 0;
}