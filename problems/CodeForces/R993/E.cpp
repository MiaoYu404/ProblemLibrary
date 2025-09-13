#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int tt, n;

int main() {
    cin >> tt; while (tt--) {
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        vector<ll> nums;
        ll tmp = 1;
        while (tmp <= 1e9) {
            nums.push_back(tmp);
            tmp *= k;
        }
        ll ans = 0;
        for (auto kn : nums) {
            if (kn > r2) break;
            ll lb = (l2 - 1) / kn;
            ll rb = r2 / kn;
            // (lb, rb] 区间

            if (lb + 1 > r1 or rb < l1) continue;
            ll l = max(lb + 1, l1);
            ll r = min(rb, r1);
            ans += r - l + 1;
        }
        cout << ans << endl;
    }
    return 0;
}