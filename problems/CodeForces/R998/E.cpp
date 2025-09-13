#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
<<<<<<< HEAD
int fa[N], n, m1, m2;
bool visF[N], visG[N];

vector< multiset<int> > F(N), G(N);

// dsu
int get(int u) {if (u != fa[u]) fa[u] = get(fa[u]); return fa[u];}
void merge (int a, int b) {
    fa[get(a)] = get(b);
}

bool query (int a, int b) {return get(a) == get(b);}

void init() {
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= n; i++) {
        fa[i] = i; visF[i] = false; visG[i] = false;
    }

    for (int i = 1; i <= m1; i++) {
        int u, v; cin >> u >> v;
        F[u].insert(v);
        F[v].insert(u);
    }

    for (int i = 1; i <= m2; i++) {
        int u, v; cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
        merge(u, v);
    }
}

void dfsF(int u) {
    visF[u] = true;
    if (F[u].empty()) return ;
    
    for (auto v : F[u]) {
        if (!query(u, v)) {
            // G 中没有，但是 F 中有
            F[u].erase(v);
            F[v].erase(u);
        }
        if (!visF[v]) dfsF(v);
        if (F[u].empty()) break;
    }
}

void dfsG(int u) {
    visG[u] = true;
    for (auto v : G[u]) {
        if (!visG[v]) dfsG(v);
    }
}

int solve() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (visG[i] == false) {
            res--;
            dfsG(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (visF[i] == false) {
            res++;
            dfsF(i);
        }
    }
    cout << res << endl;
=======
int fa[N];
int n, m1, m2;

void init() {
    for (int i = 1;i <= n; i++) fa[i] = i;
}

// Get
int get (int x) {
    if (x == fa[x]) return x;
    return fa[x] = get(fa[x]); // 路径压缩
}

// Merge （无优化）
void merge (int x, int y) {
    fa[get[x]] = get(y); 
>>>>>>> fccd62dca2b0a6763f6371626d1f91a8cdc0a100
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt; while (tt--) {
<<<<<<< HEAD
        init();

        cout << solve() << endl;
=======
        for (int i = 1; i <= n; i++) {
            cin >> n >> m1 >> m2;
            init();

            for (int i = 1; i <= n; i++) {
                nodes[i].pre = i;
                nodes[i].next = i;
            }
            vector< vector<int> > mp(n + 1);
            for (int i = 1; i <= m1; i++) {
                int u, v; cin >> u >> v;
                merge(u, v);
                // mp[u].push_back(v);
                // mp[v].push_back(u);
            }
            
            // 比如说 x 和 y，首先要让 x 和 y 在一起，那么一定有一个公共爹；
            // 那么多对，我们就可以把编号再一次并查集；
            // 最后看每棵树里有多少个元素 然后 -1 就可以了

            for (int i = 1; i <= m2; i++)
        }
>>>>>>> fccd62dca2b0a6763f6371626d1f91a8cdc0a100
    }
    return 0;
}