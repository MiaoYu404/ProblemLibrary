#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        if (rank[rx] > rank[ry]) {
            parent[ry] = rx;
        } else if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else {
            parent[ry] = rx;
            rank[rx]++;
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m1, m2;
        cin >> n >> m1 >> m2;

        DSU dsuF(n), dsuG(n);

        for (int i = 0; i < m1; ++i) {
            int u, v;
            cin >> u >> v;
            dsuF.unite(u, v);
        }

        for (int i = 0; i < m2; ++i) {
            int u, v;
            cin >> u >> v;
            dsuG.unite(u, v);
        }

        vector<pair<int, int>> operations;

        for (int u = 1; u <= n; ++u) {
            for (int v = u + 1; v <= n; ++v) {
                if (dsuF.find(u) != dsuF.find(v) && dsuG.find(u) == dsuG.find(v)) {
                    dsuF.unite(u, v);
                    operations.emplace_back(u, v);
                }
            }
        }

        cout << operations.size() << "\n";
        for (auto [u, v] : operations) {
            cout << u << " " << v << "\n";
        }
    }

    return 0;
}