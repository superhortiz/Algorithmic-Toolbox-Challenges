#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <limits>

using std::vector;
using std::string;
using std::pair;
using std::min;

long long distance(const pair<int, int>& p1, const pair<int, int>& p2) {
    long long dx = static_cast<long long>(p1.first - p2.first);
    long long dy = static_cast<long long>(p1.second - p2.second);
    return dx * dx + dy * dy;
}

void recursive_min_distance(const vector<pair<int, int>>& points, vector<pair<int, int>>& points_to_check,
                            size_t left, size_t right, long long& min_distance) {
    
    // Base case, obtains min distance for 3 or less points
    if (right - left <= 3) {
        for (size_t i = left; i < right; ++i) {
            for (size_t j = i + 1; j <= right; ++j) {
                min_distance = min(min_distance, distance(points[i], points[j]));
            }
        }
        return;
    }

    // Divide the points in 2 halves and obtain the min distance recursively
    size_t mid = left + (right - left) / 2;
    recursive_min_distance(points, points_to_check, left, mid, min_distance);
    recursive_min_distance(points, points_to_check, mid + 1, right, min_distance);

    // Populate the vector points_to_check with the points inside the strip
    double division = (points[mid].first + points[mid + 1].first) / 2.0;
    points_to_check.clear();
    for (size_t i = left; i <= right; ++i) {
        if ((points[i].first - division) * (points[i].first - division) < min_distance) {
            points_to_check.push_back(points[i]);
        }
    }

    // Sort by y-coordinate
    std::sort(points_to_check.begin(), points_to_check.end(), [] (const auto& a, const auto& b) {return a.second < b.second;} );
    double sqrt_dist = std::sqrt(min_distance);

    // For each point, compute its distance to the seven subsequent points
    if (!points_to_check.empty()) {
        for (size_t i = 0; i < points_to_check.size() - 1; ++i) {
            for (size_t j = i + 1; j < points_to_check.size() && j < i + 7; ++j) {
                // Only consider the points close enough
                if (points_to_check[j].second - points_to_check[i].second < sqrt_dist) {
                    min_distance = min(min_distance, distance(points_to_check[i], points_to_check[j]));
                }
            }
        }
    }
    return;
}

double minimal_distance(vector<int>& x, vector<int>& y) {
    size_t n_points = x.size();

    // Create vector points which contains the coordinates (x, y)
    // points_to_check is a vector to reuse resources
    vector<pair<int, int>> points(n_points), points_to_check;
    for (size_t i = 0; i < n_points; ++i) {
        points[i] = pair<int, int>(x[i], y[i]);
    }

    // Sort points by x-coordinate
    std::sort(points.begin(), points.end(), [] (const auto& a, const auto& b) {return a.first < b.first;} );

    // Define min_distance as a big value
    long long min_distance = std::numeric_limits<long long>::max();

    // Call the recursive function and return the result
    recursive_min_distance(points, points_to_check, 0, n_points - 1, min_distance);
    return std::sqrt(min_distance);
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}
