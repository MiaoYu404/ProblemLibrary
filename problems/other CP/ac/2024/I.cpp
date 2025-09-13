#include <iostream>
#include <vector>
using namespace std;

// 使用深度优先搜索来寻找连通分量的数量
void dfs(int node, vector<int>& a, vector<bool>& visited) {
    while (!visited[node]) {
        visited[node] = true;
        node = a[node - 1];  // 转到下一座城市（1-based 转换为 0-based 索引）
    }
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        vector<bool> visited(n + 1, false);
        int cycle_count = 0;

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                cycle_count++;
                dfs(i, a, visited);
            }
        }
        
        cout << cycle_count - 1 << endl;
    }

    return 0;
}
