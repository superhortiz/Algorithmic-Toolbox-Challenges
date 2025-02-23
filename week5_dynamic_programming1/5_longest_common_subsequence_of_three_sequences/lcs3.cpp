#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
    int rows = a.size();
    int cols = b.size();
    int depth = c.size();
    vector<vector<vector<int>>> alignment(rows + 1, vector<vector<int>>(cols + 1, vector<int>(depth + 1, 0)));

    int top, left, front, diag;
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            for (int k = 1; k <= depth; ++k) {
                top = alignment[i - 1][j][k];
                left = alignment[i][j - 1][k];
                front = alignment[i][j][k - 1];
                diag = alignment[i - 1][j - 1][k - 1] + ((a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])? 1 : 0);
                alignment[i][j][k] = std::max({top, left, front, diag});
            }
        }
    }
    return alignment[rows][cols][depth];
}

int main() {
    size_t an;
    std::cin >> an;
    vector<int> a(an);
    for (size_t i = 0; i < an; i++) {
        std::cin >> a[i];
    }
    size_t bn;
    std::cin >> bn;
    vector<int> b(bn);
    for (size_t i = 0; i < bn; i++) {
        std::cin >> b[i];
    }
    size_t cn;
    std::cin >> cn;
    vector<int> c(cn);
    for (size_t i = 0; i < cn; i++) {
        std::cin >> c[i];
    }
    std::cout << lcs3(a, b, c) << std::endl;
}
