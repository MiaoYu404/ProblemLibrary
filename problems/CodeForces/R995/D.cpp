#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int tt; cin >> tt; while (tt--) {
        ll n, x, y;
        cin >> n >> x >> y;
        vector<ll> num;
        ll sum = 0;

        for (int i = 1; i <= n; i++) {
            ll tmp; cin >> tmp;
            num.push_back(tmp);
            sum += tmp;
        }

        sort(num.begin(), num.end());
        ll ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (sum - num[i] < x) break;

            int l = i + 1, r = n - 1, mid;
            ll rb = sum > x ? sum - x : sum + 1;
            while (l < r) {
                mid = (l + r + 1) >> 1;
                ll p = num[i] + num[mid];
                if (p <= rb) l = mid;
                else r = mid - 1;
            }
            ll ans1 = l;

            l = i + 1, r = n - 1;
            ll lb = sum > y ? sum - y : 0;
            while (l < r) {
                mid = (l + r) >> 1;
                ll p = num[i] + num[mid];
                if (p >= lb) r = mid;
                else l = mid + 1;
            }
            ll ans2 = l;

            ll add = ans1 - ans2 + 1;
            if (num[i] + num[ans1] > rb or num[i] + num[ans2] < lb) add = 0;
            ans += add;
        }
        cout << ans << endl;
    }
}