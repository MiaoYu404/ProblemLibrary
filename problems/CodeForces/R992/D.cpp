#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// 结点v，邻边集g，深度h，父级p
void dfs (int v, vector <vector <int> >& g, vector<int>& h, int p) {
    h[v] = h[p] + 1;                // 树的深度
    for (int u : g[v]) {            // 遍历所有树枝
        if (u == p) continue;       // 防止重边
        dfs(u, g, h, v);
    }
}

int main() {
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector< vector<int> > g(n + 1);
        for (int i = 1; i <= n - 1; i++) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> h(n + 1);
        h[0] = 0;
        dfs(1, g, h, 0);
        vector< vector<int> >hs(n + 1);
        
        for (int i = 1; i <= n; i++) hs[h[i]].push_back(i);

        int l = 2, r = 2 * n;
        int cur = 0;
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; i++) {  // 定【深度 1 】为根节点
            if (cur) {
                for (int v : hs[i]) {
                    ans[v] = r;
                    r -= 2;
                }
            }
            else {
                for (int v : hs[i]) {
                    ans[v] = l;
                    l += 2;
                }
            }
            cur ^= 1;                   // 间断赋值
        }

        bool found = false;
        for (int i = 1; i <= n; i++) {
            for (int v : g[i]) {
                if (h[v] < h[i]) continue;          // 找深度较深的一侧
                if (abs(ans[v] - ans[i]) == 2) {
                    ans[v] = ans[i] - 1;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}