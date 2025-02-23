#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long MaxPairwiseProduct(const vector<int>& numbers) {
    long long max1 = 0, max2 = 0;

    for (const auto& number : numbers) {
        if (number > max1) {
            max2 = max1;
            max1 = number;
        } else if (number > max2) {
            max2 = number;
        }
    }
    return max1 * max2;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
