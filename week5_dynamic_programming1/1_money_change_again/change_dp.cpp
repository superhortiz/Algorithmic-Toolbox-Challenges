#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

int get_change(int m) {
    const std::vector<int> coins = {1, 3, 4};
    std::vector<int> n_coins(m + 1);
    n_coins[0] = 0;
    int min_num_coins;

    for (int money = 1; money <= m; ++money) {
        min_num_coins = std::numeric_limits<int>::max();
        for (const auto& coin : coins) {
            if (coin <= money) {
                min_num_coins = std::min(min_num_coins, n_coins[money - coin] + 1);
            }
        }
        n_coins[money] = min_num_coins;
    }
    return n_coins.back();
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
