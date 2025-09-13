#include <bits/stdc++.h>
using namespace std;

#define FOR(i, x, y) for (int i = x; i <= y; i++)
#define mp make_pair
#define fi first
#define se second

typedef unsigned long long ull;
typedef long long ll;

const int N = 1e5 + 10;

int h[N], siz[N];
vector <int> e[N];

void dfs (int u) {
    int size = 0;
    for (auto v : e[u]) {
        h[v] = h[u] + 1;
        dfs(v);
        size += siz[v];
    }
    siz[u] = size + 1;
}

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
    }
    
    h[1] = 1;
    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << h[i] << " " << n - siz[i] + 1 << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

    return 0;
}

// 记得开 long long