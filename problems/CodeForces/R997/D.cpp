#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        bool vis[11];
        memset(vis, false, sizeof(vis));
        vector<int> num(n + 1);
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            vis[x] = true;
            num[i] = x;
        }
        unsigned long long ans;
        if (n % 2 == 0) ans = 1LL * n / 2 * (n + 1);
        else ans = 1LL * n * ((n + 1) / 2);

        for (int x = 1; x <= 10; x++) {
            if (!vis[x]) continue;
            unordered_map<int, ll> mp;
            vector<ll> cnt(n + 1);
            ll sum = 0;

            // 记录 j 指到新的起点；
            int j = 0; cnt[0] = 0;

            for (int i = 1; i <= n; i++) {
                int val = num[i];
                cnt[i] = cnt[i - 1] + (val > x ? 1 : -1);
                if (val == x) {
                    while (j < i) {
                        mp[cnt[j]] ++;
                        j++;
                    }
                }
                sum += mp[cnt[i]];
            }
            ans -= sum;
        }

        cout << ans << endl;
    }
}