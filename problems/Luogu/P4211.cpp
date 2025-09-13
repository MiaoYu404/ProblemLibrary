// P4211 [LNOI2014] LCA
// tags: 线段树、树链剖分、LCA
// 难度: 省选 / NOI-
// link: https://www.luogu.com.cn/problem/P4211

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define lson rt << 1, l, mid
#define rson (rt << 1) + 1, mid + 1, r
#define all rt, l, r

using ll = long long;

const int MOD = 201314;
const int N = 5e4 + 10; 
struct Q {
    int ans1 = 0; int ans2 = 0;
    Q () {ans1 = ans2 = 0;}
} que[N];

struct Q_part {
    int num = 0, pos = 0, z = 0;
    bool flag = false;

    Q_part () {num = pos = z = flag = 0;}
    Q_part (int a, int b, int c, bool d) {
        num = a, pos = b, z = c, flag = d;
    }

    inline bool operator< (const Q_part a) const{
        return this -> pos < a.pos;
    }
} que_p[N << 1];

int n, q;
vector<int> e[N];
int siz[N], dep[N], fa[N], hson[N];
int tp[N], bm[N], dfn[N], rnk[N];

void dfs1 (int u) {
    dep[u] = dep[fa[u]] + 1;
    int s = 1;
    for (auto v : e[u]) {
        dfs1(v);
        s += siz[v];
        if (siz[hson[u]] < siz[v]) hson[u] = v;
    }
    siz[u] = s;
}

void dfs2(int u, int top) {
    static int t = 0;
    tp[u] = top;
    dfn[u] = ++t;
    rnk[t] = u;
    if (hson[u] != 0) {
        dfs2(hson[u], top);
        for (auto v : e[u]) {
            if (v != hson[u]) dfs2(v, v);
        }
    }
    bm[u] = t;
}

int nowL, nowR, sum[N << 2], col[N << 2];

void color(int rt, int l, int r, int co) {
    sum[rt] = (sum[rt] + (r - l + 1) * co) % MOD;
    if (l < r) col[rt] = (col[rt] + co) % MOD;
}

void pushup (int rt) {
    sum[rt] = (sum[rt * 2] + sum[rt * 2 + 1]) % MOD;
}

void pushdown (int rt, int l, int r) {
    if (col[rt] and l < r) {
        int mid = (l + r) >> 1;
        color(lson, col[rt]);
        color(rson, col[rt]);
    }

    col[rt] = 0;
}

int query(int rt, int l, int r) {
    if (nowL <= l and r <= nowR) return sum[rt];

    pushdown(all);
    int ans = 0;
    int mid = (l + r) >> 1;
    if (nowL <= mid) ans += query(lson);
    if (mid < nowR) ans += query(rson);
    return ans % MOD;
}

void modify(int rt, int l, int r) {
    if (nowL <= l and r <= nowR) {
        color(all, 1); return ;
    }

    pushdown(all);
    int mid = (l + r) >> 1;
    if (nowL <= mid) modify(lson);
    if (mid < nowR) modify(rson);

    pushup(rt);
}

int queryChain (int x, int y) {
    int tx = tp[x], ty = tp[y], ans = 0;
    while (tx != ty) {
        if (dep[tx] < dep[ty]) {
            swap(x, y); swap(tx, ty);
        }
        nowL = dfn[tx], nowR = dfn[x];
        ans = (ans + query(1, 1, n)) % MOD;
        x = fa[tx]; tx = tp[x];
    }
    if (dep[x] > dep[y]) swap(x, y), swap(tx, ty);
    nowL = dfn[x], nowR = dfn[y];
    ans = (ans + query(1, 1, n)) % MOD;
    return ans % MOD;
}

void modifyChain(int x, int y) {
    int tx = tp[x], ty = tp[y];
    while (tx != ty) {
        if (dep[tx] < dep[ty]) {swap(x, y); swap(tx, ty);}
        nowL = dfn[tx]; nowR = dfn[x];
        modify(1, 1, n);
        x = fa[tx]; tx = tp[x];
    }
    if (dep[x] > dep[y]) {swap(x, y); swap(tx, ty);}
    nowL = dfn[x], nowR = dfn[y];
    modify(1, 1, n);
}

void solve () {
    cin >> n >> q;
    for (int v = 2; v <= n; v++) {
        int u; cin >> u;
        ++u;
        e[u].pb(v);
        fa[v] = u;
    }

    for (int i = 1; i <= q; i++) {
        int l, r, z; cin >> l >> r >> z;
        ++r, ++z;
        que_p[2 * i - 1] = Q_part(i, l, z, 0);
        que_p[2 * i] = Q_part(i, r, z, 1);
    }

    dep[1] = 1;
    dfs1(1);
    dfs2(1, 1);

    sort(que_p + 1, que_p + 1 + 2 * q);

    int now = 0;
    for (int i = 1; i <= 2 * q; i++) {
        while (now < que_p[i].pos) {
            modifyChain(1, ++now);
        }

        int k = que_p[i].num;
        if (que_p[i].flag) que[k].ans1 = queryChain(1, que_p[i].z);
        else que[k].ans2 = queryChain(1, que_p[i].z);
    }

    for (int i = 1; i <= q; i++) {
        cout << (que[i].ans1 - que[i].ans2 + MOD) % MOD << endl;
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    solve();

    return 0;
}

// 记得开 long long