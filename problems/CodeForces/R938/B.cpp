#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, c, d;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt; while (tt--) {
        cin >> n >> c >> d;
        unordered_map<ll, int> mp;
        ll minn = 1e9 + 10;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ll x; cin >> x;
                mp[x] ++;
                minn = min(minn, x);
            }
        }
        ll st = minn; bool flag = true;
        for (int i = 1; i <= n; i++) {
            for (ll j = 1, x = st; j <= n; j++, x += d) {
                if (mp[x]) mp[x] --;
                else {
                    flag = false; break;
                }
            }
            st += c;
            if (!flag) break;
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}