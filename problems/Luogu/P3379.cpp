// Luogu P3379 【模板】最近公共祖先
// 倍增法

#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
const int M = 5e5 + 10;

vector<int> edge[N];
int vis[N];
int h[N];           // 深度
int f[N][25];       // 父节点数组

int lca (int a, int b) {
    if (h[a] < h[b]) swap(a, b);
    for (int i = 22; i >= 0; i--) {
        if (h[f[a][i]] >= h[b]) a = f[a][i];
    }

    if (a == b) { return a; }

    // a == b;
    for (int i = 22; i >= 0; i--) {
        if (f[a][i] != f[b][i]) {
            a = f[a][i];
            b = f[b][i];
        }
    }

    return f[a][0];
}

void dfs(int u, int fa) {
    f[u][0] = fa;
    h[u] = h[fa] + 1;
    for (auto v : edge[u]) if (v != fa) dfs(v, u);
}

int main () {
    int n, m, S;
    cin >> n >> m >> S;
    // 建树
    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    h[0] = 0;
    dfs(S, 0);

    // 初始化倍增父节点数组
    for (int i = 1; (1 << i) <= n; i++) {
        for (int x = 1; x <= n; x++) {
            f[x][i] = f[f[x][i - 1]][i - 1];
        }
    }
    
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << endl;
    }
}