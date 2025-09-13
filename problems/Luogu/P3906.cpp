// Luogu P3906
// tag: 最短路
// 难度: 普及/ 提高-
// link: https://www.luogu.com.cn/problem/P3906

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, x, y) for (int i = x; i <= y; i++)
#define mp make_pair
#define fi first
#define se second

typedef unsigned long long ull;
typedef long long ll;

const int N = 40 + 5;
int n, m, d;
int dis[N][N];

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        dis[u][v] = 1;
        dis[v][u] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
            }
        }
    }

    cin >> d;
    while (d--) {
        int u, v; cin >> u >> v;
        int tot = dis[u][v];
        vector<int> ans;
        ans.push_back(u); ans.push_back(v);
        for (int i = 1; i <= n; i++) {
            if (dis[i][u] + dis[i][v] == dis[u][v]) ans.push_back(i);
        }
        sort(ans.begin(), ans.end());
        for (auto x : ans) printf("%d ", x);
        printf("\n");
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