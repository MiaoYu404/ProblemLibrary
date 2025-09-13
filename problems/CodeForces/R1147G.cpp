// Codeforces 1147 G
// tag: dp, game
// diff: 
// link: https://codeforces.com/contest/2137/problem/G
#include <bits/stdc++.h>

using ll = long long;
using i64 = ll;
using ull = unsigned long long;
using u64 = ull;

constexpr i64 MOD = 998244353;
constexpr int N = 2e5 + 10;

int n, m, q;
// bool vis[N];
std::vector<int> to[N], from[N];

struct node{
    int i;
    bool color;     // false: blue, true: red
    bool win[2];    // [0]: cry wins? [1]: river wins?
    int num[2];     // [0]: num of C no, [1]: num of R no;
    node() {}
    node(int _i) : node(_i, false) {}
    node(int _i, bool _color) : i(_i), color(_color) {
        win[0] = true; win[1] = false;
        num[0] = 0; num[1] = 0;
    }
};
std::vector<node> nodes;

void updateWins(int v, int la) {
    // if (vis[v]) return ;
    // vis[v] = true;
    node &curr = nodes[v];

    bool tmpC = curr.win[0], tmpR = curr.win[1];
    if (curr.color) {
        curr.win[0] = false;
        curr.win[1] = true;
    } else {
        curr.win[0] = curr.num[1] ? true : false;
        curr.win[1] = curr.num[0] ? true : false;
    }
    int dC = 0, dR = 0;
    if (tmpC) dC = curr.win[0] ? 0 : 1;
    else dC = curr.win[0] ? -1 : 0;
    if (tmpR) dR = curr.win[1] ? 0 : 1;
    else dR = curr.win[1] ? -1 : 0;

    if (dC == 0 and dR == 0) return ;
    for (int u : from[v]) {
        if (u == la) continue;
        nodes[u].num[0] += dC, nodes[u].num[1] += dR;
        updateWins(u, v);
    }
}

void turnRed(int u) {
    nodes[u].color = true;
    // std::fill(vis + 1, vis + 1 + n, false);
    updateWins(u, 0);
}

void init() {
    nodes.clear(); nodes.push_back( node() );
    for (int i = 1; i <= n; i++) {
        nodes.push_back( node(i) );
    }
    for (int i = 1; i <= n; i++) {
        to[i].clear();
        from[i].clear();
    }
}
void solve() {
    std::cin >> n >> m >> q;
    init();
    for (int i = 1; i <= m; i++) {
        int u, v; std::cin >> u >> v;
        to[u].push_back(v);
        from[v].push_back(u);
        nodes[u].num[1]++;
    }

    while (q--) {
        int x, u; std::cin >> x >> u;
        if (x == 1) turnRed(u);
        else {
            if (nodes[u].win[0]) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }   
    }
}

int main () {
    std::cin.tie(0), std::cout.tie(0);

    int tt; std::cin >> tt; while (tt--) {
        solve();
    }

    return 0;
}

// 记得开 long long