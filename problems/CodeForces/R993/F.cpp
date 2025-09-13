#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 2e5 + 10;
int tt, n, m, q;
int a[maxn], b[maxn];
ll tot = 0;

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[i] = x;
    }
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        b[i] = x;
        for (int i = 1; i <= n; i++) tot += x * a[i];
    }

    set<ll> num;
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= m; c++) {
            ll tmp = 0;
            for (int r2 = 1; r2 <= n; r2++) tmp += b[c] * a[r2];
            for (int c2 = 1; c2 <= m; c2++) tmp += a[r] * b[c2];
            tmp -= a[r] * b[c];
            ll rsl = tot - tmp;
            num.insert(rsl);
        }
    }

    while (q--) {
        ll x; cin >> x;
        if (num.count(x)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}