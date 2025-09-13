#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1e5+10;
vector<int> children[N];
int parent[N];
bool a[N];

void dfs(int x)
{
    if(a[x]) return;
    a[x] = true;
    cout << x << " ";
    for(auto i : children[x]) dfs(i);
}

int main(){
    int n, m; cin >> n >> m;
    memset(a, false, sizeof(a));
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;

        children[x].push_back(y);
        parent[y] = x;
    }
    for(int i = 1; i <= n; i++) sort(children[i].begin(), children[i].end());

    dfs(1);
    cout << endl;
    memset(a, false, sizeof(a));

    queue<int> q; q.push(1);
    while(!q.empty()){
        int y = q.front(); q.pop();
        if(a[y]) continue;
        a[y] = true;
        for(auto i : children[y]) q.push(i);
        cout << y << " ";
    }
}