#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt; cin >> tt; while (tt--) {
        ll n, k; cin >> n >> k;
        ll ans = 0;
        queue< pair<ll, ll> > q;
        q.push(make_pair(1, n));
        while (!q.empty()) {
            pair<ll, ll> x = q.front(); q.pop();
            ll l = x.first, r = x.second;
            ll len = r - l / 2;
            int t = 0;
            while (len % 2 != 1) {
                len /= 2;
                ++t;
            }
            if (len >= k) {
                len = (len - (len % 2)) / 2;
                ll tmp = len;
                len += l - 1;
                ans += pow(2, t) * (len) + pow(2, t) * tmp;
                for (int i = l; i < r; i += 2 * tmp - 1) {
                    q.push(make_pair(i, i + tmp - 2));
                    q.push(make_pair(i + tmp, i + 2 * tmp - 2));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}