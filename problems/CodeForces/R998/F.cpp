#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
using ll = unsigned long long;

const int N = 1e5 + 10;
ll dp[N][20];
int k, n;

ll ksm (ll a, ll n) {
    ll sum = 1;
    while(n) {
        if(n & 1) sum = sum * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return sum;
}
ll nCr (ll n, ll m) {
    ll fm = 1, fz = 1;
    for(int i = 1; i <= m; ++i) {
        fm = fm * i % MOD;
        fz = fz * (n - i + 1) % MOD;
    }
    return fz * ksm(fm, MOD-2) % MOD;
}
ll Lucas(ll n, ll m) {
    if(!m) return 1;
    return nCr(n % MOD, m % MOD) * Lucas(n / MOD, m / MOD) % MOD;
}
//主函数中直接输出Lucas(n, m)就是组合数的答案了


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    vector<vector<int> > div(N);
    
    for (int i = 2; i <= N / 2; i++) {
        for (int j = 1; i * j <= 1e5; j++) {
            div[i * j].push_back(i);
        }
    }

    for (int x = 2; x <= 1e5; x++) {
        dp[x][1] = 1;
        for (int j = 2; j <= 16; j++) {dp[x][j] = 0;}
    }

    for (int j = 2; j <= 16; j++) {
        for (int x = 2; x <= 1e5; x++) {
            for (auto p : div[x]) {
                dp[x][j] += dp[x / p][j - 1];
            }
        }
    }

    int tt; cin >> tt; while (tt--) {
        cin >> k >> n;

        /*
        for (int i = 1; i <= k; ++i) {
            cout << "[" << i << "] ";
            for (int j = 1; j <= 16; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        */
        
        cout << n % MOD << " ";
        for (int x = 2; x <= k; x++) {
            ll ans = 0;
            for (int j = 1; j <= 16; j++) {
                ans += Lucas(n + 1, j + 1) * dp[x][j];
                ans %= MOD;
            }
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}