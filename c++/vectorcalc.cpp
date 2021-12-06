#include <iostream>
#include <cmath>
#include <vector>

int calc(int num) {
    int s = num * num;
    return sqrt(s);
}
int list(int num) {
    std::vector<int> list;
    for (int i = 1; i <= calc(num); i++) {
        list.push_back(i);
    }
    return list.size();
}
int main() {
    int i;
    std::cin >> i;
    if (i < 500) {
        int m = i * 500;
        m += i;
        std::cout << list(calc(m % 500)) << std::endl;
    } else {
        std::cout << list(calc(i)) << std::endl;
    }
    return 0;
}
