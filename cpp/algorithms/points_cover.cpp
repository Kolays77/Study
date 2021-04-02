#include <vector>
#include <iostream>
#include <algorithm>
#define DEBUG(x) std::cout << #x << " = " << (x) << std::endl;
// I don't remember what it's for

unsigned PointsCover(std::vector<double>& v) {
	if (!v.size()) {
		return 0;
	}
	std::sort(v.begin(), v.end());
	unsigned ans = 1;	
	unsigned left = v.front();
	unsigned right = left + 1;
	unsigned i = 1;
	while (i < v.size()) {
		if (v[i] > right) {
			++ans ;
			left = v[i];
			right = left + 1;
		}
		++i;
	}	
	return ans;
}



int main() {
	std::vector<double> v = {1.,1.2,1.3,1.55555};
	std::cout << PointsCover(v) << std::endl;
	return 0;
}