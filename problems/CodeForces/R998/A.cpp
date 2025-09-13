#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt; while (tt--) {
        int a[6];
        for (int i = 1; i <= 5; i++) {
            if (i == 3) continue;
            int x; cin >> x;
            a[i] = x;
        }
        a[3] = a[1] + a[2];
        int ans = 0;
        int cnt = 0;
        for (int i = 1; i <= 3; i++) {
            if (a[i] + a[i + 1] == a[i + 2]) cnt++;
        }
        ans = max(cnt, ans);
        a[3] = a[4] - a[2];

        cnt = 0;
        for (int i = 1; i <= 3; i++) {
            if (a[i] + a[i + 1] == a[i + 2]) cnt++;
        }

        a[3] = a[5] - a[4];
        ans = max(cnt, ans);

        cnt = 0;
        for (int i = 1; i <= 3; i++) {
            if (a[i] + a[i + 1] == a[i + 2]) cnt++;
        }
        ans = max(cnt, ans);
        cout << ans << endl;
    }
    return 0;
}