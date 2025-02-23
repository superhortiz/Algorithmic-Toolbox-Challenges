#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
    vector<int> summands;
    int i = 1, sum = 0;
    while (sum + i <= n) {
        sum += i;
        summands.push_back(i);
        i++;
    }
    sum -= summands.back();
    summands.pop_back();
    summands.push_back(n - sum);
    return summands;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
}
