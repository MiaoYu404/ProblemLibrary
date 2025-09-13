#include <iostream>
#include <vector>
using namespace std;

bool canMakeNonDecreasing(const vector<int>& a) {
    int n = a.size();
    int x = n - 1;

    // Find the first index from the right where a[x] > a[x + 1]
    while (x > 0 && a[x - 1] <= a[x]) {
        --x;
    }

    // If no such x is found, the array is already non-decreasing
    if (x == 0) {
        return true;
    }

    // Check if we can resolve the issue by removing 1 to x-1 or 1 to x
    int max_left = a[0];
    for (int i = 1; i < x; ++i) {
        if (a[i] > max_left) {
            max_left = a[i];
        }
    }

    return (x == 1 || a[x - 1] <= a[x] || max_left <= a[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (canMakeNonDecreasing(a)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
