#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> fast_count_segments(vector<int>& starts, vector<int>& ends, vector<int>& points) {
    size_t n_points = points.size();
    vector<int> cnt(n_points);
    vector<size_t> indices(n_points);

    for (size_t i = 0; i <n_points; ++i) {
        indices[i] = i;
    }

    // Sort vectors
    std::sort(starts.begin(), starts.end());
    std::sort(ends.begin(), ends.end());
    std::sort(indices.begin(), indices.end(), [&points](auto a, auto b) {return points[a] < points[b];});

    // Iterate over points
    size_t start = 0, end = 0;
    for (size_t i = 0; i < n_points; ++i) {
        while (start < starts.size() && starts[start] <= points[indices[i]]) {
            start++;
        }
        while (end < ends.size() && ends[end] < points[indices[i]]) {
            end++;
        }
        cnt[indices[i]] = start - end;
    }
    return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = 0; j < starts.size(); j++) {
        cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
        }
    }
    return cnt;
}

int main() {
    int n, m;
    // n: number of segments
    // m: the number of points
    std::cin >> n >> m;
    vector<int> starts(n), ends(n);
    for (size_t i = 0; i < starts.size(); i++) {
        std::cin >> starts[i] >> ends[i];
    }
    vector<int> points(m);
    for (size_t i = 0; i < points.size(); i++) {
        std::cin >> points[i];
    }
    //use fast_count_segments
    vector<int> cnt = fast_count_segments(starts, ends, points);
    for (size_t i = 0; i < cnt.size(); i++) {
        std::cout << cnt[i] << ' ';
    }
}
