#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt; while (tt--) {
        int n, m; cin >> n >> m;
        ll ans = 0;
        int x, y; cin >> x >> y;
        ans += 4 * m;
        for (int i = 2; i <= n; i++) {
            cin >> x >> y;
            ans += 2 * (y + x);
        }
        cout << ans << endl;
    }
}