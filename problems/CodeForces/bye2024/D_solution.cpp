#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int qpow (int a, int x = MOD - 2) {
    int res = 1;
    for (; x; x >>= 1, a = 1ll * a * a % MOD) {
        if (x & 1) res = 1ll * res * a % MOD;
    }
    return res;
}

const int N = 2e5 + 5;

int a[N], b[N], c[N], d[N];
void solve() {
    int n, q, res = 1; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i], c[i] = a[i];
    for (int i = 1; i <= n; i++) cin >> b[i], d[i] = b[i];
    sort(c + 1, c + 1 + n);
    sort(d + 1, d + 1 + n);
    for (int i = 1; i <= n; ++i) {
        res = 1ll * res * min(c[i], d[i]) % MOD;
    }

    cout << res << " \n"[q == 0];
    for (int i = 1, op, x; i <= q; ++i) {
        cin >> op >> x;
        if (op == 1) {
            int p = upper_bound(c + 1, c + 1 + n, a[x]) - c - 1;
            if (c[p] < d[p]) res = 1ll * res * qpow(c[p]) % MOD * (c[p] + 1) % MOD;
            ++a[x], ++c[p];
        } else {
            int p = upper_bound(d + 1, d + 1 + n, b[x]) - d - 1;
            if (d[p] < c[p]) res = 1ll * res * qpow(d[p]) % MOD * (d[p] + 1) % MOD;
            ++b[x], ++d[p];
        }
        cout << res << " \n"[i == q];
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int tt; cin >> tt; while (tt--){
        solve();
    }
    return 0;
}