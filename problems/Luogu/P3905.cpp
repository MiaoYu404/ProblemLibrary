// Luogu P3905
// tag: 最短路
// 难度: 普及/ 提高-
// link: https://www.luogu.com.cn/problem/P3905

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, x, y) for (int i = x; i <= y; i++)
#define mp make_pair
#define fi first
#define se second

typedef unsigned long long ull;
typedef long long ll;

const int N = 100 + 5;
int n, m, d;
int nodes[N];
int weight[N][N];

vector<int> edges[N];

void dij(int s, int t) {
    int dis[N], vis[N];
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    dis[s] = 0;
    for (int i = 1; i <= n; i++) {
        int minx = -1;
        for (int x = 1; x <= n; x++) {
            if (vis[x]) continue;
            if (minx == -1) minx = x;
            if (dis[minx] > dis[x]) minx = x;
        }
        vis[minx] = true;

        for (auto v : edges[minx]) {
            if (vis[v]) continue;
            dis[v] = min(dis[minx] + weight[minx][v], dis[v]);
        }
        if (minx == t) {
            cout << dis[t] << endl;
            return ;
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, l; cin >> u >> v >> l;
        weight[u][v] = l * -1;
        weight[v][u] = l * -1;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cin >> d;
    for (int i = 1; i <= d; i++) {
        int u, v; cin >> u >> v;
        weight[u][v] *= -1;
        weight[v][u] *= -1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            weight[i][j] = max(weight[i][j], 0);
        }
    }

    int s, t; cin >> s >> t;
    dij(s, t);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    solve();

    return 0;
}

// 记得开 long long