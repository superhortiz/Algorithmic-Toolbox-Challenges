#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
    if (op == '*') {
        return a * b;
    } else if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else {
        assert(0);
    }
}

void min_max(vector<vector<long long>>& min_values, vector<vector<long long>>& max_values, const vector<char>& operations, int i, int j) {
    long long max_val = std::numeric_limits<long long>::min();
    long long min_val = std::numeric_limits<long long>::max();
    long long a, b, c, d;

    for (int k = i; k < j; ++k) {
        a = eval(max_values[i][k], max_values[k + 1][j], operations[k]);
        b = eval(max_values[i][k], min_values[k + 1][j], operations[k]);
        c = eval(min_values[i][k], max_values[k + 1][j], operations[k]);
        d = eval(min_values[i][k], min_values[k + 1][j], operations[k]);
        min_val = min({min_val, a, b, c, d});
        max_val = max({max_val, a, b, c, d});
    }
    min_values[i][j] = min_val;
    max_values[i][j] = max_val;
}


long long get_maximum_value(const string &exp) {
    vector<int> digits;
    vector<char> operations;
    for (size_t i = 0; i < exp.size(); ++i) {
        if (i % 2 == 0) {
            digits.push_back(exp[i] - '0');
        } else {
            operations.push_back(static_cast<char>(exp[i]));
        }
    }

    int n_digits = digits.size();
    vector<vector<long long>> min_values(n_digits, vector<long long>(n_digits, 0));
    vector<vector<long long>> max_values(n_digits, vector<long long>(n_digits, 0));

    for (size_t i = 0; i < n_digits; ++i) {
        min_values[i][i] = digits[i];
        max_values[i][i] = digits[i];
    }

    int j;
    for (int s = 1; s < n_digits; ++s) {
        for (int i = 0; i < n_digits - s; ++i) {
            j = i + s;
            min_max(min_values, max_values, operations, i, j);
        }
    }
    return max_values[0][n_digits - 1];
}

int main() {
    string s;
    std::cin >> s;
    std::cout << get_maximum_value(s) << '\n';
}
