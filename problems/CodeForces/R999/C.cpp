#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int dp[N][3][N];
int a[N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            a[i] = x;
        }
        dp[1][1][0] = 1;
        dp[1][2][1] = 1;
        for (int i = 1; i <= n; i++) {
            dp[n][1][i] = 0;
            dp[n][2][i] = 0;
        }
        
        vector< set<int> > liars(n);
        liars[1].insert(0), liars[1].insert(1);
        for (int i = 1; i < n; i++) {
            int flag = 0;
            for (auto k : liars[i]) {
                if (dp[i][1][k] > 0) {
                    flag++;

                    dp[i + 1][2][k + 1] += dp[i][1][k];
                    dp[i + 1][2][k + 1] %= MOD;

                    liars[i + 1].insert(k + 1);
                }

                if (a[i + 1] == k) {
                    dp[i + 1][1][k] += dp[i][1][k]; flag++;
                    dp[i + 1][1][k] %= MOD;

                    dp[i + 1][1][k] += dp[i][2][k]; flag++;
                    dp[i + 1][1][k] %= MOD;
                    liars[i + 1].insert(k);
                }
            }
            if (flag == 0) break;
        }

        ll ans = 0;
        for (int k = 1; k <= n; k++) {
            ans += dp[n][1][k];
            ans %= MOD;
            ans += dp[n][2][k];
            ans %= MOD;
        }

        cout << ans << endl;
    }
    return 0;
}