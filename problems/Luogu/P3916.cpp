#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
vector<int> G[N];
int ans[N];

void dfs(int u, int d){
    if(ans[u]) return ;
    ans[u] = d;
    for(int i = 0; i < G[u].size(); i++) dfs(G[u][i], d);
}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        G[v].push_back(u);
    }

    for(int i = n; i >= 1; i--) dfs(i, i);
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}