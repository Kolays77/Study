#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << 1 << '\n' << 1;
        return 0;
    }
    int i = 1;
    std::vector<int> ans;
    while (n) {
        if (n <= 2*i) 
            i = n;
        n -= i;
        ans.push_back(i);
        ++i;	
	}


    std::cout << ans.size() << std::endl;
    for (int item: ans) {
        std::cout << item << " ";
    }

    return 0;
}