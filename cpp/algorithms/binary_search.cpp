#include <iostream>
#include <vector>



int find_lower(const std::vector<int>& a, int x) { // max i : a[i] <= x
	int l = -1; // a[l] <= x
	int r = (int)a.size(); // a[r] > x
	while (r > l + 1) { // соседние
		int m = (r + l) / 2;
		if (a[m] <= x) {
            l = m;
        } else {
            r = m;
        }
	}
	return l;
}

int find_upper(const std::vector<int>& a, int x) { // max i : a[i] <= x
	int l = -1; // a[l] < x
	int r = (int)a.size(); // a[r] >= x
	while (r > l + 1) { // соседние
		int m = (r + l) / 2;
		if (a[m] < x) {
            l = m;
        } else {
            r = m;
        }
	}
	return r;
}

bool find(const std::vector<int>& a, int x) {
	int pos = find_lower(a,x);
    return pos >= 0 && a[pos] == x;
}

int main() {
	int value;
	std::cin >> value;
	std::vector<int> v = {1,2,3,4,5,5,6,7,7,7,7,7,7,33,44};
	if (find(v, value)) {
        std::cout << "YES";
    }
	return 0;
}