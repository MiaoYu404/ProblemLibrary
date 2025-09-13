// Codeforces Round 549 (Div. 2) C. Queen
// tags: dfs
// 难度: *1400
// link: https://codeforces.com/problemset/problem/1143/C

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, x, y) for (int i = x; i <= y; i++)
#define mp make_pair
#define fi first
#define se second

typedef unsigned long long ull;
typedef long long ll;

const int N = 1e5 + 10;
int fa[N], rsp[N];
vector<int> e[N];
vector<int> ans;

bool dfs(int u) {
    if (e[u].empty()) {
        if (rsp[u]) ans.push_back(u);
        return rsp[u];
    }
    bool flag = rsp[u];
    for (auto v: e[u]) {
        flag &= dfs(v);
    }
    if (flag) ans.push_back(u);
    return rsp[u];
}

void solve()
{
    int n; cin >> n;
    int rt = -1;
    for (int v = 1; v <= n; v++) {
        int u, c; cin >> u >> c;
        rsp[v] = c;
        if (u == -1) {rt = v; continue;}
        fa[v] = u;
        e[u].push_back(v);
    }

    dfs(rt);
    if (ans.empty()) {cout << -1 << endl; return ;}
    sort(ans.begin(), ans.end());
    for (auto x : ans) {
        if (x == rt) continue;
        cout << x << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    solve();

    return 0;
}

// 记得开 long long