#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Find the largest m >= 2 such that m*(m-1)/2 <= k
int find_max_m(ll k) {
    int low = 2, high = 500;
    while (low < high) {
        int mid = (low + high + 1) / 2;
        ll f_mid = (ll)mid * (mid - 1) / 2;
        if (f_mid <= k) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        ll k;
        cin >> k;
        if (k == 0) {
            // Place 500 staffs, each on a unique row and column
            int n = 500;
            cout << n << endl;
            for (int i = 1; i <= n; ++i) {
                cout << i << " " << i << endl;
            }
        } else {
            // Greedy algorithm to find group sizes
            vector<int> ai;
            while (k > 0) {
                int m = find_max_m(k);
                ai.push_back(m);
                k -= (ll)m * (m - 1) / 2;
            }
            // Assign coordinates
            vector<pair<int, int>> points;
            int col = 1;
            for (int i = 0; i < ai.size(); ++i) {
                int row = i + 1;
                for (int j = 0; j < ai[i]; ++j) {
                    points.push_back({row, col + j});
                }
                col += ai[i];
            }
            int n = points.size();
            cout << n << endl;
            for (auto p : points) {
                cout << p.first << " " << p.second << endl;
            }
        }
    }
    return 0;
}