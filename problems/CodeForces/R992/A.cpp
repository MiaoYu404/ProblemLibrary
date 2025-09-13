#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 10;

int main() {
    int t; cin >> t; while (t--) {
        int n, k; cin >> n >> k;
        int a[maxn];
        bool vis[maxn];
        memset(vis, true, sizeof(vis));
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (abs(a[j] - a[i]) % k == 0) {
                    vis[i] = false; break;
                }
            }
        }

        bool flag = false;
        int i;
        for (i = 1; i <= n; i++) if (vis[i]) {
            flag = true; break;
        }
        if (flag) cout << "YES\n" << i << "\n";
        else cout << "NO"<< '\n';
    }
}