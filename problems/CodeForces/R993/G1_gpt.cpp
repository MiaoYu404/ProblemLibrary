#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 10;
int tt, n;
int r[maxn];
int state[maxn]; // 0未访问,1访问中,2已完成
bool in_cycle[maxn];
int dist_[maxn];
vector<int> adj[maxn]; // 逆图

int cycle_start;
vector<int> cycle_nodes;

void dfs_find_cycle(int u) {
    state[u] = 1;
    int v = r[u];
    if (state[v] == 0) {
        dfs_find_cycle(v);
    } else if (state[v] == 1) {
        // 找到环，从v开始回溯
        int cur = v;
        while (true) {
            in_cycle[cur] = true;
            cur = r[cur];
            if (cur == v) break;
        }
    }
    state[u] = 2;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tt;
    while (tt--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> r[i];
            in_cycle[i] = false;
            state[i] = 0;
            adj[i].clear();
        }
        // 构建逆图
        for (int i = 1; i <= n; i++) {
            adj[r[i]].push_back(i);
        }

        // 找环节点
        for (int i = 1; i <= n; i++) {
            if (state[i] == 0) {
                dfs_find_cycle(i);
            }
        }

        // 对于环节点dist=0， 非环节点dist=inf
        // 多源BFS，从所有环节点出发往回层次遍历
        queue<int>q;
        for (int i = 1; i <= n; i++) {
            if (in_cycle[i]) {
                dist_[i] = 0;
                q.push(i);
            } else {
                dist_[i] = 1000000000;
            }
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto v: adj[u]) {
                if (!in_cycle[v] && dist_[v] > dist_[u] + 1) {
                    dist_[v] = dist_[u] + 1;
                    q.push(v);
                }
            }
        }

        int mx = 0;
        for (int i = 1; i <= n; i++) {
            if (!in_cycle[i]) {
                mx = max(mx, dist_[i]);
            }
        }

        cout << mx + 2 << "\n";
    }

    return 0;
}
