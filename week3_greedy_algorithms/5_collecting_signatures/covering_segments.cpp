#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
    int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
    vector<int> points;
    std::sort(segments.begin(), segments.end(), [] (auto& a, auto& b) {return a.start < b.start;});

    int min_end = INT_MAX;
    for (auto& segment : segments)
        if (segment.start > min_end) {
            points.push_back(min_end);
            min_end = segment.end;
        } else if (segment.end < min_end) {
            min_end = segment.end;
        }
    points.push_back(min_end);
    return points;
}

int main() {
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
}
