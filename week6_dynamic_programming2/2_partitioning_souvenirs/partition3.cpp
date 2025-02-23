#include <iostream>
#include <vector>

using std::vector;

int partition3(vector<int> &A) {
    int total_sum = 0;
    for (const auto& element : A) {
        total_sum += element;
    }
    if (total_sum % 3 != 0) return 0;
    int sum = total_sum / 3;
    int val1, val2, vi;

    vector<vector<vector<int>>> values(A.size() + 1, vector<vector<int>>(sum + 1, vector<int>(sum + 1, 0)));
    values[0][0][0] = 1;
    for (int i = 1; i <= A.size(); ++i) {
        for (int j = 0; j <= sum; ++j) {
            for (int k = 0; k <= sum; ++k) {
                if (values[i - 1][j][k] == 1) {
                    values[i][j][k] = 1;
                } else {
                    vi = A[i - 1];
                    val1 = (vi <= j)? values[i - 1][j - vi][k] : 0;
                    val2 = (vi <= k)? values[i - 1][j][k - vi] : 0;
                    values[i][j][k] = val1 || val2;
                }
            }
        }
    }
    return values[A.size()][sum][sum];
}

int main() {
    int n;
    std::cin >> n;
    vector<int> A(n);
    for (size_t i = 0; i < A.size(); ++i) {
        std::cin >> A[i];
    }
    std::cout << partition3(A) << '\n';
}
