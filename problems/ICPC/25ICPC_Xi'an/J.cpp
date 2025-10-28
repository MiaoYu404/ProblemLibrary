// 2025 ICPC Xi'an J January's Color
// tag: 树链剖分、DFS、DP
// link: https://qoj.ac/contest/2558/problem/14690

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 3e5 + 5;

int n, m;
ll costs[N];
vector<int> edges[N];

int f[N], d[N], hson[N], siz[N];
int t[N], b[N], dfn[N], ra[N];
ll bestCost[N];

int tree_build(int u, int dep) {
    hson[u] = 0; siz[hson[u]] = 0;
    d[u] = dep; siz[u] = 1;

    priority_queue<ll> pq;
    for (int v : edges[u]) {
        if (v == f[u]) continue;
        f[v] = u;
        siz[u] += tree_build(v, dep + 1);
        if (siz[v] > siz[hson[u]]) hson[u] = v;

        pq.push(bestCost[v]);
        if (pq.size() > 2) pq.pop();
    }
    if (!pq.empty()) {
        ll val1 = pq.top();
        pq.pop();
        ll val2 = pq.top();
        pq.pop();
        bestCost[u] = min(bestCost[u], val1 + val2);
    }

    return siz[u];
}


ll pre[N];
int tot = 0;
void tree_decomposition(int u, int top) {
    t[u] = top;
    tot++;
    dfn[u] = tot; ra[tot] = u;    // dfn & rank

    pre[dfn[u]] = u == top ? 0 : pre[dfn[u] - 1];

    ll best = LONG_MAX;
    if (u != top) {
        int father = f[u];
        for (int v : edges[father]) {
            if (v == f[father]) continue;
            if (v == hson[father]) continue;

            best = min(best, bestCost[v]);
        }
        pre[dfn[u]] += best;
    }

    if (hson[u] != 0) {
        tree_decomposition(hson[u], top);

        for (int v : edges[u]) {
            if (v == f[u]) continue;
            if (v == hson[u]) continue;
            
            // 轻子结点
            tree_decomposition(v, v);
        }
    }
}

void init() {
    for (int i = 1; i <= n; i++) {
        bestCost[i] = LONG_MAX;
        edges[i].clear();
    }
}

ll cal(int u, int target) {
    if (t[u] == t[target] && d[target] <= d[u]) {
        return pre[dfn[u]] - pre[dfn[target]];
    }
    else if (t[u] == 1 or d[target] > d[u]) return -1;  // the top heavy chain, but it is not here.

    // still go up
    ll best = LONG_MAX;
    int topFather = f[t[u]];
    for (int v : edges[topFather]) {
        if (v == f[topFather]) continue;
        if (v == t[u]) continue;

        best = min(best, bestCost[v]);
    }

    ll tmp = cal(topFather, target);
    return tmp == -1 ? -1 : tmp + best + pre[dfn[u]];
}

void solve() {
    std::cin >> n >> m;
    init();
    for (int i = 1; i <= n; i++) {
        int c; std::cin >> c;
        bestCost[i] = c;
    }
    for (int i = 1; i <= n - 1; i++) {
        int u, v; std::cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    tree_build(1, 1);
    tree_decomposition(1, 1);

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        cout << cal(u, v) << endl;
    }
}

int main () {
    cin.tie(0);

    int tt; std::cin >> tt; while (tt--) {
        solve();
    }
}