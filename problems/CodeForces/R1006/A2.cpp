#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n, k, p;
        cin >> n >> k >> p;
        int abs_k = abs(k);
        int m = (abs_k + p - 1) / p; // Ceiling division
        if (m <= n) {
            cout << m << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}