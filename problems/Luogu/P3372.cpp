#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;

struct node{
    int l, r;
    ll val;
    int lazy = 0;
}t[4 * N + 2];

ll a[N + 2];

void build (int u, int l, int r) {
    t[u].l = l;
    t[u].r = r;
    if (l == r) {
        t[u].val = a[l];
        return;
    }

    int mid = l + ((r - l) >> 1);
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
    
    // 区间求和
    t[u].val = t[u * 2].val + t[u * 2 + 1].val;
}

// 更新父节点
void pushup(int u) {
    t[u].val = t[u * 2].val + t[u * 2 + 1].val;
}

// 更新子节点
void pushdown(int u) {
    // 懒惰标记往下走
    t[u * 2].lazy += t[u].lazy;
    t[u * 2 + 1].lazy += t[u].lazy;

    t[u * 2].val += t[u].lazy * (t[u * 2].r - t[u * 2].l + 1);
    t[u * 2 + 1].val += t[u].lazy * (t[u * 2 + 1].r - t[u * 2 + 1].l + 1);

    t[u].lazy = 0;
}

// 单点修改
void modify (int u, int x, int y) {
    if (t[u].l == t[u].r) {
        t[u].val = y;
        return ;
    }
    int mid = (t[u].l + t[u].r) >> 1;
    if (x <= mid) modify(u * 2, x, y);
    else modify(u * 2 + 1, x, y);

    //t[u].val = t[u * 2].val + t[u * 2 + 1].val;
    pushup(u);
}

// 区间修改
void modify2(int u, int l, int r, ll x) {
    if (l <= t[u].l && t[u].r <= r) {
        t[u].lazy += x;
        t[u].val += x * (t[u].r - t[u].l + 1);
        return ;
    }

    int mid = (t[u].l + t[u].r) / 2;
    pushdown(u);
    if (l <= mid) modify2(u * 2, l, r, x);
    if (mid < r) modify2(u * 2 + 1, l, r, x);

    pushup(u);
}

// 区间查询
ll query(int u, int L, int R) {
    if (t[u].l > R || t[u].r < L) return 0; // 找不到
    // 正好是
    if (t[u].l >= L && t[u].r <= R) return t[u].val;

    pushdown(u);
    return query(u * 2, L, R) + query(u * 2 + 1, L, R);
}

int main () {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x; a[i] = x;
    }
    build(1, 1, n);

    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int x, y;
            ll k;
            cin >> x >> y >> k;
            modify2(1, x, y, k);
        }else {
            int x, y; cin >> x >> y;
            cout << query(1, x, y) << endl;
        }
    }
    return 0;
}