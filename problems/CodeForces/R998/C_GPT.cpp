#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> x(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }

        // Sort the array
        sort(x.begin(), x.end());

        int score = 0;
        int left = 0, right = n - 1;

        while (left < right) {
            int sum = x[left] + x[right];

            if (sum == k) {
                // Pair found, increment score and move both pointers
                ++score;
                ++left;
                --right;
            } else if (sum < k) {
                // If sum is too small, move the left pointer to increase the sum
                ++left;
            } else {
                // If sum is too large, move the right pointer to decrease the sum
                --right;
            }
        }

        cout << score << "\n";
    }

    return 0;
}
