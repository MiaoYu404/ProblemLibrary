#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000+10;

int t, n;
int r[MAXN];
bool in_cycle[MAXN];
int state[MAXN]; // 0=unvisited,1=visiting,2=done
int dist_[MAXN]; 

int N;
vector<int> adj[MAXN]; // reversed graph: adj[u] = {v | r[v]=u}

// 环检测
int stk[MAXN], top;
void dfs_find_cycle(int u) {
    state[u] = 1;
    stk[++top] = u;
    int v = r[u];
    if (state[v] == 0) {
        dfs_find_cycle(v);
    } else if (state[v] == 1) {
        // 找到环，从v开始回溯
        int pos = top;
        while (stk[pos] != v) pos--;
        for (int i = pos; i <= top; i++) {
            in_cycle[stk[i]] = true;
        }
    }
    state[u] = 2;
    top--;
}

// 计算节点的耗尽时间T
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> r[i];
            in_cycle[i] = false;
            state[i] = 0;
            adj[i].clear();
        }

        // 找环
        for (int i = 1; i <= n; i++) {
            if (state[i] == 0) {
                top = 0;
                dfs_find_cycle(i);
            }
        }

        // 建立反向图
        // adj[u] = {v | r[v]=u}
        for (int i = 1; i <= n; i++) {
            adj[r[i]].push_back(i);
        }

        // 耗尽时间T数组
        vector<int> T(n+1, -1);

        // 子节点计数
        vector<int> children_count(n+1, 0);
        for (int u = 1; u <= n; u++) {
            children_count[u] = (int)adj[u].size();
        }

        // 环节点T=0已知，加入队列
        queue<int>q;
        for (int i = 1; i <= n; i++) {
            if (in_cycle[i]) {
                T[i] = 0;
                q.push(i);
            }
        }

        // 拓扑式计算T
        // 已知环节点T=0，通过其子节点计算父节点的T
        // 对于u, 当children_count[u]=0时，可计算T[u]
        // 这里需要说明：在公式T_u= max(T_ci + i)中，T_ci来自adj[u]，即u的子节点在反向图中是u的“前置”？
        // 实际上adj[u]给出u的子节点(在T意义下)，我们要等待这些子节点的T已知后才能算u的T。
        // 当我们弹出一个节点x时，说明x的T已知，x的父节点是r[x]，父节点等待x这个孩子的T。
        
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            int p = r[cur]; // 父节点(在forward图中cur->p)
            if (!in_cycle[cur]) {
                // 非环节点的T尚未计算或已计算完毕
                // 不需要在这里计算cur的T，因为在推入q之前已计算完
            }

            // cur是p的一个子节点，p等待cur的T
            if (!in_cycle[p] || T[p] == 0) { 
                // p不是环节点或已是环节点(T=0已知)
                // 减少父节点未处理孩子计数
                children_count[p]--;
                if (children_count[p] == 0 && !in_cycle[p]) {
                    // 所有子节点T已知，计算T[p]
                    // 收集p的子节点T值
                    vector<int> children_T;
                    for (auto c: adj[p]) {
                        children_T.push_back(T[c]);
                    }
                    // 加上p自己的0(代表p的初始1个玩偶)
                    children_T.push_back(0);

                    // 降序排序
                    sort(children_T.begin(), children_T.end(), greater<int>());

                    int val = 0; 
                    for (int i = 0; i < (int)children_T.size(); i++) {
                        val = max(val, children_T[i] + i);
                    }
                    T[p] = val;
                    q.push(p);
                }
            }
        }

        // 找非环节点的最大T值
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            if (!in_cycle[i]) {
                mx = max(mx, T[i]);
            }
        }

        cout << mx + 2 << "\n";
    }
    return 0;
}
