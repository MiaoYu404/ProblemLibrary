#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        vector<int> a;
        for (int i = 1; i<= n; i++) {
            int x; cin >> x;
            a.push_back(x);
        }
        bool flag = false;
        for (int i = 0; i < n - 1; i++) {
            int x = min(a[i], a[i + 1]);
            int y = max(a[i], a[i + 1]);
            if (x * 2 > y) {
                flag = true; break;
            }
        }
        if (flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}