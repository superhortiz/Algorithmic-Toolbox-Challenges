#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

int edit_distance(const string &str1, const string &str2) {
    int rows = str1.length();
    int cols = str2.length();
    vector<vector<int>> alignment(rows + 1, vector<int>(cols + 1, 0));
    for (int i = 1; i <= rows; ++i) {
        alignment[i][0] = i;
    }
    for (int j = 1; j <= cols; ++j) {
        alignment[0][j] = j;
    }

    int top, left, diag;
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            top = alignment[i - 1][j] + 1;
            left = alignment[i][j - 1] + 1;
            diag = alignment[i - 1][j - 1] + ((str1[i - 1] == str2[j - 1])? 0 : 1);
            alignment[i][j] = std::min({top, left, diag});
        }
    }
    return alignment[rows][cols];
}

int main() {
    string str1;
    string str2;
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2) << std::endl;
    return 0;
}
