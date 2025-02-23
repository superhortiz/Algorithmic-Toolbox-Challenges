#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>

using std::vector;
using std::swap;

std::tuple<int, int> partition3(vector<int> &a, int l, int r) {
    int x = a[l];
    int m1 = l, m2 = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] < x) {
            m1++;
            m2++;
            swap(a[i], a[m2]);
            swap(a[m1], a[m2]);
        } else if (a[i] == x) {
            m2++;
            swap(a[i], a[m2]);
        }
    }
    swap(a[l], a[m1]);
    return std::make_tuple(m1, m2);
}

int partition2(vector<int> &a, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);

    int m1, m2;
    std::tie(m1, m2) = partition3(a, l, r);

    randomized_quick_sort(a, l, m1 - 1);
    randomized_quick_sort(a, m2 + 1, r);
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    randomized_quick_sort(a, 0, a.size() - 1);

    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
}
