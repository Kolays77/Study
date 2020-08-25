#include <iostream> 
#include <algorithm>
#include <vector>
#include <iomanip>
struct Item {
    Item(int w_, int c_) : w(w_), c(c_) {}
    int w;
    int c;
};

bool operator<(const Item& lhs, const Item& rhs) { 
    return (lhs.c /lhs.w) > (rhs.c / rhs.w);
}

int main() {
    int n;
    int W;
    std::cin >> n >> W;
    std::vector<Item> v;

    int item_c;
    int item_w;
    double max = 0;
    while (n) {
        std::cin >> item_c >> item_w;
        v.emplace_back(Item{item_w,item_c});
        n--;
    }
    if (!W) {
        std::cout << std::fixed << std::setprecision(3) << max << std::endl;
        return 0;
    }
    std::sort(v.begin(), v.end());
    

    for (Item& item: v) {
        if (W == 0) {
            break;
        }
         
        if (W > item.w) {
            max += item.c;
            W -= item.w;
            continue;
        }

        max += W*item.c/item.w;
        W = 0; 
    }

    std::cout << std::fixed << std::setprecision(3) << max << std::endl;
    return 0;
}