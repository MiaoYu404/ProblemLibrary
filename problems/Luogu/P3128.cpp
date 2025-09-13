// P3128 [USACO15DEC] Max Flow P
// tag: LCA，树上差分
// 难度: 普及+ / 提高
// link: https://www.luogu.com.cn/problem/P3128

#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;
using ll = long long;

int n, k;
vector<int> e[N];
int f[N][25], dep[N];
int pre[N];
int ans = 0;

void init() {
    for (int i = 1; (1 << i) <= n; i++) {
        for (int u = 1; u <= n; u++) {
            f[u][i] = f[f[u][i - 1]][i - 1];
        }
    }
    memset(pre, 0, sizeof(pre));
}

void dfs(int u, int fa) {
    f[u][0] = fa;
    for (auto v : e[u]) if (v != fa) {
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int i = 22; i >= 0; i--) {
        if (dep[f[v][i]] >= dep[u]) v = f[v][i];
    }

    if (u == v) return u;

    for (int i = 22; i >= 0; i--) {
        if (f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }
    }

    return f[u][0];
}

int tmp = 0;

int dfs2(int u, int fa) {
    int val = 0;
    for (auto v : e[u]) {
        if (v != fa) val += dfs2(v, u);
    }
    val += pre[u];
    ans = max(val, ans);
    return val;
}

int main () {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dep[0] = 0; dep[1] = 1;
    dfs(1, 0); init();

    for (int i = 1; i <= k; i++) {
        int u, v; cin >> u >> v;
        int l = lca(u, v);
        pre[u]++, pre[v]++, pre[l]--;
        pre[f[l][0]]--;
    }

    dfs2(1, 0);
    cout << ans << endl;
}