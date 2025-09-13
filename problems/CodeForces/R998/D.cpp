#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
ll num[N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            ll x; cin >> x;
            num[i] = x;
        }
        num[0] = -1;

        int st = 1;
        for (; st <= n - 1; st++) {
            if (num[st] <= num[st + 1]) {
                num[st + 1] -= num[st];
                num[st] = 0;
            } else break;
        }
        if (st == n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}