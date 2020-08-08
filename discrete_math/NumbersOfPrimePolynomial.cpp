#include <iostream>
#include <cmath>
// it is uses formula 
using namespace std;
int NumberOfPimeDividers(int n){
  int prime[12] = {2,3,5,7,11,13,17,19,23,29,31,33};
  int count = 0;
  for(int i = 0; i<12; i++){
    if (n==1)
      return count;

    while (n % prime[i] == 0) {
      count++;
      n = n / prime[i];
    };
  }
  return count;
}


int mu(int n) {
  if (n == 1)
    return 1;
  else
    return pow((-1), NumberOfPimeDividers(n));
}


int number(int n) {
  int prime[12] = {2,3,5,7,11,13,17,19,23,29,31,33};
  double answer = pow(2,n);
  for(int i= 0; i < 12; i++){
    if(n % prime[i] == 0)
      answer += mu(prime[i]) * pow(2, (n/prime[i]));
  }
  return (ceil(answer/n));
}


int main() {
  for (int i = 1; i < 36; i++)
    cout << i << ": " << number(i) << endl;
  return 0;
}