#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_sequence(int n) {
    std::vector<int> n_operations(n + 1), last_values(n + 1), sequence;
    n_operations[1] = 0;
    int min_operations, last_value;

    for (int number = 2; number <= n; ++number) {
        last_value = number - 1;
        min_operations = n_operations[number - 1];

        if (number % 2 == 0 && n_operations[number / 2] < min_operations) {
            last_value = number / 2;
            min_operations = n_operations[number / 2];
        }

        if (number % 3 == 0 && n_operations[number / 3] < min_operations) {
            last_value = number / 3;
            min_operations = n_operations[number / 3];
        }
        n_operations[number] = min_operations + 1;
        last_values[number] = last_value;
    }
    sequence.push_back(n);
    while (n != 1) {
        sequence.push_back(last_values[n]);
        n = last_values[n];
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

vector<int> greedy_sequence(int n) {
    std::vector<int> sequence;
    while (n >= 1) {
        sequence.push_back(n);
        if (n % 3 == 0) {
            n /= 3;
        } else if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n - 1;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> sequence = optimal_sequence(n);
    std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
}
