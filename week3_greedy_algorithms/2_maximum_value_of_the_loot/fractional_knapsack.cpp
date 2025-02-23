#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // For std::greater

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<pair<double, int>> prices;
  int n = weights.size();
  for (int i = 0; i < n; ++i)
    prices.push_back({(1.0 * values[i]) / weights[i], i});
  
  sort(prices.rbegin(), prices.rend());

  int a;
  for (int i = 0; i < n; ++i) {
    if (capacity == 0) return value;
    a = min(weights[prices[i].second], capacity);
    value += a * prices[i].first;
    capacity -= a;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}
