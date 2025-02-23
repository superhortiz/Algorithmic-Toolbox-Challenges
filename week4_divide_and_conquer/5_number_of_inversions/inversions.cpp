#include <iostream>
#include <vector>

using std::vector;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
    long long number_of_inversions = 0;
    if (right <= left) return number_of_inversions;
    size_t mid = left + (right - left) / 2;
    number_of_inversions += get_number_of_inversions(a, b, left, mid);
    number_of_inversions += get_number_of_inversions(a, b, mid + 1, right);

    // Fill the auxiliar copy of the vector (b)
    for (size_t i = left; i <= right; ++i)
        b[i] = a[i];

    // Merge for loop
    size_t i = left, j = mid + 1;
    for (size_t k = left; k <= right; ++k) {
        if (i > mid)
            a[k] = b[j++];
        else if (j > right) {
            a[k] = b[i++];
        }
        else if (b[i] <= b[j]) {
            a[k] = b[i++];
        }
        else {
            number_of_inversions += mid - i + 1;
            a[k] = b[j++];
        }
    }
    return number_of_inversions;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    vector<int> b(a.size());
    std::cout << get_number_of_inversions(a, b, 0, a.size() - 1) << '\n';
}
