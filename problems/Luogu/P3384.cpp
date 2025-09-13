// P3384 【模板】重链剖分/树链剖分
// tag: 树链剖分、线段树、LCA
// 难度: 提高+ / 省选-
// link: https://www.luogu.com.cn/problem/P3384

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
vector<int> e[N];
int f[N], d[N], hson[N], s[N];
int t[N], b[N], dfn[N], ra[N];

void dfs1(int u, int fa) {
    // father, deep, heavyson, size
    int size = 1;
    f[u] = fa;
    d[u] = d[fa] + 1;
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        if (hson[u] < s[v]) {hson[u] = v;}
        size += s[v];
    }
    s[u] = size;
};

int cnt = 0;
void dfs2(int u, int top) {
    // top, dfn, rank
    // rank(dfn(x)) = x;
    t[u] = top;
    cnt++;
    dfn[u] = cnt;
    ra[cnt] = u;
    if (hson[u] != 0) {
        dfs2(hson[u], top);
        for (auto v : e[u]) {                           // 保证无自环
            if (v == f[u] or v == hson[u]) continue;    // 不能是父亲
            else dfs2(v, v);
        }
    }
    b[u] = ra[cnt];
}

struct node {
    int l, r;
    ll val = -1;
    int lazy = 0;
}tr[4 * N + 2];

ll a[N];

void pushup(int u) {
    tr[u].val = tr[u * 2].val + tr[u * 2 + 1].val;
}

void build(int u, int l, int r) {
    tr[u].l = l, tr[u].r = r;
    if (l == r) {
        tr[u].val = a[ra[l]]; return ;
    }

    int mid = l + ((r - l) >> 1);
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
    pushup(u);
}

void pushdown(int u) {
    tr[u * 2].lazy += tr[u].lazy;
    tr[u * 2 + 1].lazy += tr[u].lazy;

    tr[u * 2].val += tr[u].lazy * (tr[u * 2].r - tr[u * 2].l + 1);
    tr[u * 2 + 1].val += tr[u].lazy * (tr[u * 2 + 1].r - tr[u * 2 + 1].l + 1);

    tr[u].lazy = 0;
}

void modify2(int u, int l, int r, ll x) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].lazy += x;
        tr[u].val += x * (tr[u].r - tr[u].l + 1);
        return ;
    }

    int mid = (tr[u].l + tr[u].r) / 2;
    pushdown(u);
    if (l <= mid) modify2(u * 2, l, r, x);
    if (mid < r) modify2(u * 2 + 1, l, r, x);

    pushup(u);
}

ll query(int u, int L, int R) {
    if (tr[u].l > R or tr[u].r < L) return 0;

    if (tr[u].l >= L and tr[u].r <= R) return tr[u].val;

    pushdown(u);
    return query(u * 2, L, R) + query(u * 2 + 1, L, R);
}

void addPath(int u, int v, int x) {
    while (t[u] != t[v]) {
        if (d[t[u]] < d[t[v]]) swap(u, v);
        modify2(1, dfn[t[u]], dfn[u], x);
        u = f[t[u]];
    }
    if (dfn[u] > dfn[v]) swap(u, v);
    modify2(1, dfn[u], dfn[v], x);
}

ll queryPath(int u, int v) {
    ll tot = 0;
    while (t[u] != t[v]) {
        if (d[t[u]] < d[t[v]]) swap(u, v);
        tot += query(1, dfn[t[u]], dfn[u]);
        u = f[t[u]];
    }
    if (dfn[u] > dfn[v]) swap(u, v);
    tot += query(1, dfn[u], dfn[v]);
    return tot;
}

void addSonT(int u, int x) {
    modify2(1, dfn[u], dfn[b[u]], x);
}

ll querySonT(int u) {
    return query(1, dfn[u], dfn[b[u]]);
}

void solve () {
    int n, m, R; ll P; cin >> n >> m >> R >> P;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs1(R, 0);
    dfs2(R, R);
    build(1, 1, n);

    for (int i = 1; i <= m; i++) {
        int op; cin >> op;
        if (op == 1) {
            int x, y, z; cin >> x >> y >> z;
            addPath(x, y, z);
        } else if (op == 2) {
            int x, y; cin >> x >> y;
            cout << queryPath(x, y) % P << endl;
        } else if (op == 3) {
            int x, z; cin >> x >> z;
            addSonT(x, z);
        } else {
            int x; cin >> x;
            cout << querySonT(x) % P << endl;
        }
    }
}

int main () {
    solve();
    return 0;
}