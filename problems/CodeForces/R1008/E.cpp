#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    // First query with n=0 to get x + y
    cout << 0 << endl;
    cout.flush();
    ll sum_xy;
    cin >> sum_xy;

    // Second query with all bits set to 1
    ll mask = (1LL << 30) - 1;
    cout << mask << endl;
    cout.flush();
    ll both_or;
    cin >> both_or;

    // Read '!' and m
    cout << "!" << endl;
    cout.flush();
    ll m;
    cin >> m;

    // Calculate carry and determine each bit's contribution
    vector<int> bit_sum(30, 0);
    ll carry = 0;
    for (int i = 0; i < 30; ++i) {
        ll s_i = (sum_xy >> i) & 1;
        ll total = s_i - carry;
        if (total < 0) {
            // sum_i is 0, carry was 1, so x_i + y_i could be 1
            bit_sum[i] = 1;
            carry = 1;
        } else {
            if (total % 2 == 0) {
                // x_i + y_i is total (0 or 2)
                bit_sum[i] = total;
                carry = total / 2;
            } else {
                // x_i + y_i is total (1)
                bit_sum[i] = 1;
                carry = 0;
            }
        }
    }

    // Compute the answer based on m's bits
    ll answer = 0;
    for (int i = 0; i < 30; ++i) {
        if (m & (1LL << i)) {
            answer += (1LL << i) * 2;
        } else {
            answer += (1LL << i) * bit_sum[i];
        }
    }

    cout << answer << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}