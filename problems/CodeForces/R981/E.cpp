#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;

bool vis[maxn];
int cnt;
int p[maxn];

void dfs (int u) {
    if (vis[u]) return;
    vis[u] = true;
    cnt++;
    dfs(p[u]);
}

int main () {
    int tt; cin >> tt; while(tt--) {
        int n; cin >> n;
        memset(vis, false, sizeof(vis));
        int ans = 0;
        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            cnt = 0;
            dfs(i);
            if (cnt > 2) ans += (cnt - 1) / 2;
        }
        cout << ans << endl;
    }
}