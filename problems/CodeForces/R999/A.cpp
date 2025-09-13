#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        int odd = 0, even = 0;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            if (x % 2) odd++;
            else even++;
        }
        if (even == 0) cout << max(odd - 1, 0) << endl;
        else cout << odd + 1 << endl;
    }
    return 0;
}