#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
    if (left == right) return -1;
    if (left + 1 == right) return a[left];

    int max_count = 0;
    std::unordered_map<int, int> counter;

    for (int& element : a) {
        if (max_count < ++counter[element])
            max_count = counter[element];
    }
    return (max_count > (a.size() / 2))? 1 : -1;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
