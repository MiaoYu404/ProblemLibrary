#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int tt, n;
const int maxn = 2e5 + 10;

int main() {
    cin >> tt; while (tt--) {
        cin >> n;
        int a[maxn];
        bool vis[maxn];
        memset(vis, false, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            a[i] = x;
        }

        int tmp = 1;
        for (int i = 1; i <= n; i++) {
            int x = a[i];
            if (vis[x]) {
                while(vis[tmp]) {
                    tmp++;
                    if (tmp > n) tmp = 1;
                }
                cout << tmp << " ";
                vis[tmp] = true;
                continue;
            }
            else {
                cout << x << " ";
                vis[x] = true;
            }
        }
        cout << endl;
    }
    return 0;
}