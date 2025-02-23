#include <iostream>
#include <vector>

int fibonacci_sum_squares(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0, current  = 1;
    std::vector<long long> pisano;
    pisano.push_back(previous);
    pisano.push_back(current);

    for (int i = 2; ; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        pisano.push_back(current);
        if (previous == 0 && current == 1) break;
    }
    pisano.pop_back();
    pisano.pop_back();

    long long sum = 0;
    for (int i = 0; i <= n % pisano.size(); ++i)
        sum = (sum + pisano[i] * pisano[i]) % 10;

    return sum;
}

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_squares_naive(n) << std::endl;
    std::cout << fibonacci_sum_squares(n);
}
