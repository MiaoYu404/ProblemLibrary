#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

// 快速幂
ll pow_mod(ll base, int exp, ll mod) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

// 计算 rev(n, p)
ll rev(ll n, int p, int mod) {
    vector<int> digits;
    ll temp = n;
    while (temp) {
        digits.push_back(temp % p);
        temp /= p;
    }
    ll ans = 0;
    for (int i = digits.size() - 1; i < digits.size(); i++) {
        ans = (ans + (ll)digits[i] * pow_mod(p, i, mod)) % mod;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll m = min(k, n);
        ll sum = 0;

        // p <= n 部分
        for (int p = 2; p <= m; p++) {
            sum = (sum + rev(n, p, MOD)) % MOD;
        }

        // p > n 部分
        if (k > n) {
            ll count = k - n;
            sum = (sum + (n % MOD) * (count % MOD)) % MOD;
        }

        cout << sum << "\n";
    }
    return 0;
}