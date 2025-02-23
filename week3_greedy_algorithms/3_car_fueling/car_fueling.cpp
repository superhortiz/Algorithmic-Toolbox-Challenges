#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int>& stops) {
    stops.push_back(dist);
    int fuel = tank, last_stop = 0, curr_stop, n_stops = 0;

    for (const auto& curr_stop : stops) {
        fuel -= curr_stop - last_stop;
        if (fuel < 0) {
            n_stops++;
            fuel = tank - (curr_stop - last_stop);
            if (fuel < 0) {return -1;}
        }
        last_stop = curr_stop;
    }
    return n_stops;
}


int main() {
    int d = 0; // Distance
    cin >> d;
    int m = 0; // Miles on a full tank
    cin >> m;
    int n = 0; // Number of gas stations
    cin >> n;

    vector<int> stops(n);  // Gas station distances. 0 < stop1 < stop2 < ... < stopn < d
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
