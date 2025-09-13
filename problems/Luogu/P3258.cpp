// P3258 [JLOI2014] 松鼠的新家
// tag: 差分
// 难度: 普及+ / 提高
// link: https://www.luogu.com.cn/problem/P3258

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using ll = long long;

const int MOD = 1e9 + 5;
const int N = 3e5 + 10;
vector<int> e[N];
vector<pair<int, int> > order;
int n;
int dif[N], dep[N];
int f[N][20];

void dfs(int u, int fa) {
    f[u][0] = fa;
    dep[u] = dep[fa] + 1;
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
}

void init() {
    for (int i = 1; i < 20; i++) {
        for (int u = 1; u <= n; u++) {
            f[u][i] = f[f[u][i - 1]][i - 1];
        }
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 19; i >= 0; i--) {
        if (dep[f[u][i]] >= dep[v]) u = f[u][i];
    }

    if (u == v) return u;

    for (int i = 19; i >= 0; i--) {
        if (f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }
    }
    
    return f[u][0];
}

int ans[N];
int val[N];
int dfs2(int u, int fa) {
    int sw = 0;
    for (auto v : e[u]) {
        if (fa == v) continue;
        sw += dfs2(v, u);
    }
    ans[u] = sw + dif[u];
    return ans[u];
}
void solve() {
    cin >> n;
    int st = -1, tar = -1; cin >> st;
    for (int i = 1; i < n; i++) {
        cin >> tar;
        order.push_back(make_pair(st, tar));
        st = tar; tar = -1;
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }

    dfs(1, 0);
    init();
    for (auto p : order) {
        int st = p.first, tar = p.second;
        int mid = lca(st, tar);
        dif[st]++, dif[tar]++, dif[mid]--, dif[f[mid][0]]--;
        val[tar]--;
    }

    dfs2(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] + val[i] << endl;
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    solve();
    return 0;
}

// 记得开 long long