#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility> // For std::pair
#include <functional> // For std::hash

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
    vector<vector<int>> value(W + 1, vector<int>(w.size() + 1, 0));

    for (int i = 1; i <= w.size(); ++i) {
        for (int weight = 1; weight <= W; ++weight) {
            value[weight][i] = value[weight][i - 1];
            if (w[i - 1] <= weight) {
                int val = value[weight - w[i - 1]][i - 1] + w[i - 1];
                if (value[weight][i] < val) {
                    value[weight][i] = val;
                }
            }
        }
    }
    return value[W][w.size()];
}

int main() {
    int n, W;
    std::cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    std::cout << optimal_weight(W, w) << '\n';
}
