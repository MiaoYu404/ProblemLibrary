// P1351 [NOIP 2014 提高组] 联合权值
// tag: DFS
// 难度: 普及 / 提高-
// link: https://www.luogu.com.cn/problem/P1351

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
const int MOD = 10007;

vector<int> edge[N];
int f[N];
ll sum[N];
int w[N];
ll ans = 0;
ll maxp = 0;

void dfs(int u, int fa) {
    f[u] = fa;
    int fi = 0, se = 0;
    for (auto v : edge[u]) {
        ans = (ans + w[v] * (sum[u] - w[v])) % MOD;
        if (w[fi] < w[v]) {
            se = fi; fi = v;
        } else if (w[se] < w[v]) {
            se = v;
        }
        if (v != fa) dfs(v, u);
    }
    maxp = max(maxp, (ll)(w[fi] * w[se]));
}

int main () {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    w[0] = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x; w[i] = x;
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = 0;
        for (auto v : edge[i]) sum[i] += w[v];
    }

    dfs(1, 0);
    cout << maxp << " " << ans;
}