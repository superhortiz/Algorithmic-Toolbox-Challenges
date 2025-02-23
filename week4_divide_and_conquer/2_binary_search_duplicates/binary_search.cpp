#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int rec_bin_search(const vector<int> &a, int x, int left, int right) {
    if (right < left) return -1;
    int mid = left + (right - left) / 2;
    if (x == a[mid] && x != a[mid - 1]) return mid;
    else if (x <= a[mid]) return rec_bin_search(a, x, left, mid - 1);
    else return rec_bin_search(a, x, mid + 1, right);
}

int binary_search(const vector<int> &a, int x) {
    int left = 0, right = (int)a.size() - 1; 
    return rec_bin_search(a, x, left, right);
}

int linear_search(const vector<int> &a, int x) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == x) return i;
    }
    return -1;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cout << binary_search(a, b[i]) << ' ';
    }
}
