// P1198 [JSOI2008] 最大数
// tag: 线段树
// 难度: 普及+ / 提高
// link: https://www.luogu.com.cn/problem/P1198

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;

struct node {
    int l, r;
    ll val;
} t[4 * N + 2];

ll a[N + 2];

void pushup(int u) {
    t[u].val = max(t[2 * u].val, t[2 * u + 1].val);
}

void build (int u, int l, int r) {
    t[u].l = l;
    t[u].r = r;
    if (l == r) {
        t[u].val = a[l];
        return ;
    }

    int mid = l + ((r - l) >> 1);
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);

    pushup(u);
}

void modify (int u, int x, int y) {
    if (t[u].l == t[u].r) {
        t[u].val = y;
        return ;
    }
    int mid = (t[u].l + t[u].r) >> 1;
    if (x <= mid) modify(u * 2, x, y);
    else modify(u * 2 + 1, x, y);

    pushup(u);
}

ll query(int u, int l, int r) {
    if (t[u].l > r or t[u].r < l) return 0;
    if (t[u].l >= l and t[u].r <= r) return t[u].val;

    return max(query(u * 2, l, r), query(u * 2 + 1, l, r));
}

int main () {
    int m; ll D; cin >> m >> D;
    build(1, 1, m);
    int back = 1;
    int t = 0;
    while (m--) {
        char op; ll x; cin >> op >> x;
        if (op == 'Q') {
            t = query(1, back - x, back - 1);
            cout << t << endl;
        } else { // op == 'A'
            modify(1, back, (t + x) % D);
            back++;
        }
    }

    return 0;
}