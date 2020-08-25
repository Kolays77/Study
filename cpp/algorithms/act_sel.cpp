#include <vector>
#include <algorithm>
#include <iostream>

struct Segment {
    Segment(double _l, double _r) : l(_l) , r(_r) {}
    double l;
    double r;
};

bool operator<(const Segment& lhs, const Segment& rhs) {
    if (lhs.l < rhs.l) {
        return true;
    } else if (lhs.l > rhs.l){
        return false;
    }

    if (lhs.r < rhs.r) {
        return true;
    } else {
        return false;
    }
}

size_t ActSel(std::vector<Segment>&  v) {
    if (!v.size()) {
        return 0;
    }
    size_t ans = 1;
    std::sort(v.begin(), v.end());
    double r = v.front().r;
    size_t i = 1;
    while (i < v.size()) {
        if (v[i].l > r) {
            r = v[i].r;
            ++ans;
        }
        ++i;

    }
    return ans;
}


int main() {
    std::vector<Segment> v = {{2,4},{5,10},{1,1.0001},{-1.9,0.2},{88,99}};
    std::cout << ActSel(v);
    return 0;
}