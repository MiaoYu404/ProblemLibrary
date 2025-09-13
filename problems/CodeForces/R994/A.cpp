#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[55];

int main () {
    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        bool exi1 = false, exi2 = false, exi3 = false;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            if (x == 0) exi1 = true;
            if (x != 0) exi2 = true;
            a[i] = x;
        }

        int l = 1, r = n;
        while (l <= n) {
            if (a[l] != 0) break;
            l++;
        }
        while (r >= 1) {
            if (a[r] != 0) break;
            r--;
        }

        for (int i = l; i <= r; i++) {
            if (a[i] == 0) exi3 = true;
        }

        if (!exi1) cout << 1 << '\n';
        else if (!exi2) cout << 0 << '\n';
        else if (exi3) cout << 2 << '\n';
        else cout << 1 << '\n';
    }
    return 0;
}