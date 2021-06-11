#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	int curr, need;
	cin >> curr >> need >> s;
	if(s == "auto") cout << need;
    else if(s == "heat") {
        if(curr > need) cout << curr;
        else cout << need;
    }
    else if (s == "freeze") {
        if (curr < need) cout << curr;
        else cout << need;
    }
    else cout << curr;
	return 0;
}
