#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int deg[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t; while(t--){
        int n; cin >> n;
        vector< set<int> > adj(n + 1);
        memset(deg, 0, sizeof(deg));

        for(int i = 0; i < n - 1; i++){
            int u, v; 
            cin >> u >> v;
            adj[u].insert(v);
            adj[v].insert(u);
            deg[u]++;
            deg[v]++;
        }

        if(n == 2){
            cout << 0 << "\n";
            continue;
        }

        // 记录 (度, 节点编号)，然后排序，取前若干个
        vector< pair<int, int> > nodes;
        for(int i = 1; i <= n; i++){
            nodes.push_back({adj[i].size(), i});
        }
        sort(nodes.begin(), nodes.end(), [](auto &a, auto &b){
            return a.first > b.first; // 降序
        });

        int ans = 0;
        int val = adj[nodes[1].second].size();
        for(int i = 0; i < 3; i++){
            for(int j = i + 1; (j < n); j++) {
                if (deg[nodes[j].second] != val) break;
                int a = nodes[i].second;
                int b = nodes[j].second;
                int tmp = 0;
                if(adj[a].count(b)){
                    tmp = adj[a].size() + adj[b].size() - 2;
                } else {
                    tmp = adj[a].size() + adj[b].size() - 1;
                }
                ans = max(ans, tmp);
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}
