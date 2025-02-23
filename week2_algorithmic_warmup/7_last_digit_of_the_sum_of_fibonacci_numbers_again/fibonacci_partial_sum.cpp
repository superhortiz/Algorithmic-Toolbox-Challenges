#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum(long long from, long long to) {
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
    long long pisano_from = from % pisano.size();
    long long pisano_to = to % pisano.size();

    if (pisano_from > pisano_to) pisano_to += pisano.size();

    for (long long i = pisano_from; i <= pisano_to; ++i)
        sum = (sum + pisano[i % pisano.size()]) % 10;

    return sum;
}

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
