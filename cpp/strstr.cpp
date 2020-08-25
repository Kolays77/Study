#include <iostream>
#define DEBUG(x) std::cout << #x << " = " << (x) << std::endl;

int strstr_ (const char *text, const char *pattern) {
  if (!*pattern)    
    return 0;

  for (int i = 0; *text; ++text, ++i) {
    const char* t = text;
    const char* p = pattern;
    while (*p++ == *t++)
      if (!*p) 
        return i;
  }
  return -1;
}

int strcmp(const char *a, const char *b){
    while ( *a && *b && *a == *b ) ++a, ++b;
    return *a - *b;
}

int main() {
    //std::cout << strstr("LIZA LOVES BEARS", "LOVE");
    DEBUG(strstr_("222222454545454545", "454545"));
    return 0;
}