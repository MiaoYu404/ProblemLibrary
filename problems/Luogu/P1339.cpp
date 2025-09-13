#include <bits/stdc++.h>

using namespace std;

int n, m, s, t;
const int maxn = 2505;
struct Edge{
    int v, w;
    Edge(int v, int w): v(v), w(w) {}
};

struct Node{
    int dis, u;
    Node(int dis, int u): dis(dis), u(u) {}
    friend bool operator < (Node a, Node b) {
        return a.dis < b.dis;
    }

    friend bool operator > (Node a, Node b) {
        return a.dis > b.dis;
    }
};

vector<Edge> e[maxn];
bool vis[maxn];
int dis[maxn];
priority_queue<Node, vector<Node>, greater<Node> > q;

int main() {
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        Edge e1(v, w), e2(u, w);
        e[u].push_back(e1);
        e[v].push_back(e2);
    }
    for (int i = 1; i <= n; i++) vis[i] = false;
    for (int i = 1; i <= n; i++) dis[i] = INT_MAX;

    dis[s] = 0;
    q.push(Node(0, s));

    while(!q.empty()) {
        int u = q.top().u; q.pop();
        if (!vis[u]) {
            vis[u] = true;
            for (auto x : e[u]) {
                int v = x.v;
                int w = x.w;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.push(Node(dis[v], v));
                }
            }
        }
    }
    //for (int i = 1; i <= n; i++) cout << dis[i] << " ";
    cout << dis[t] << '\n';
    return 0;
}