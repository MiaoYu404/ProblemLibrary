#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt; cin >> tt; while (tt--) {
        int n, q; cin >> n >> q;
        vector<ll> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            a[i] = x;
        }
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            b[i] = x;
        }
    }
    return 0;
}