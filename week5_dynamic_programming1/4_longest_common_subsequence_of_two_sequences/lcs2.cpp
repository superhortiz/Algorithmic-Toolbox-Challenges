#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
    int rows = a.size();
    int cols = b.size();
    vector<vector<int>> alignment(rows + 1, vector<int>(cols + 1, 0));

    int top, left, diag;
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            top = alignment[i - 1][j];
            left = alignment[i][j - 1];
            diag = alignment[i - 1][j - 1] + ((a[i - 1] == b[j - 1])? 1 : 0);
            alignment[i][j] = std::max({top, left, diag});
        }
    }
    return alignment[rows][cols];
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    size_t m;
    std::cin >> m;
    vector<int> b(m);
    for (size_t i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    std::cout << lcs2(a, b) << std::endl;
}
