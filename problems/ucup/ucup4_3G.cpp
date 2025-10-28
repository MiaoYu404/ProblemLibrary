// ucup stage 3, G
// tag: 随机，BFS
// link: https://contest.ucup.ac/contest/2559/problem/14421

#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;

int n, m, q; 
vector<int> edges[N];
int a[N], siz[N];

int get(int x) {
    if (a[x] == x) return x;
    a[x] = get(a[x]);
    return a[x];
}

void merge(int x, int y) {
    if (get(x) == get(y)) return ;
    siz[get(y)] += siz[get(x)];
    a[get(x)] = get(y);
}

// randomly choose 300 points
int dist[300][N];

void init() {
    for (int i = 1; i <= n; i++) {
        edges[i].clear();
        a[i] = i; siz[i] = 1;
        for (int j = 0; j < 300; j++) {
            dist[j][i] = N;
        }
    }
}

void solve() {
    // freopen("input.in", "r", stdin);
    cin >> n >> m >> q;
    init();
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
        merge(u, v);
    }

    set<int> chosen;
    // if (n > 20000) 
    for (int i = 0; i < min(300, n); i++) {
        int u;
        do {
            u = rand() % n + 1;
        } while(chosen.find(u) != chosen.end());
        chosen.insert(u);
        // cout << u << ": ";
        dist[i][0] = u;
        dist[i][u] = 0;

        queue<int> q;
        q.push(u);
        while (!q.empty()) {
            u = q.front(); q.pop();
            if (dist[i][u] == 20000) {
                // cout << u << " ";
                continue;
            }
            for (int v : edges[u]) {
                if (dist[i][v] != N) continue;
                q.push(v);
                dist[i][v] = dist[i][u] + 1;
            }
        }
        // cout << endl;
    }

    for (int i = 1; i <= q; i++) {
        int x, y; cin >> x >> y;

        if (get(x) != get(y)) {
            cout << "YES" << endl;
        } else {
            // same union
            if (siz[get(x)] <= 20000 or x == y) {
                cout << "NO" << endl;
                continue;
            }

            // large union
            bool flag = true;
            for (int i = 0; i < min(300, n); i++) {
                // cout << dist[i][0] << ": " << dist[i][x] << " " << dist[i][y] << endl;
                if (dist[i][x] + dist[i][y] <= 20000) {
                    // cout << dist[i][0];
                    flag = false; break;
                }
            }
            if (flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}

int main () {
    cin.tie(0);
    
    solve();

    return 0;
}