#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n,x,y; cin >> n >> x >> y;
        // 确保 x < y 不重要，但题目已给保证
        // 构造环+弦的邻接关系
        // 对于验证我们需要一份邻接表
        vector<vector<int>> adj(n+1);
        for (int i = 1; i <= n; i++) {
            adj[i].push_back(i == 1 ? n : i-1);
            adj[i].push_back(i == n ? 1 : i+1);
        }
        // 加上弦边 (x,y)
        adj[x].push_back(y);
        adj[y].push_back(x);

        // 尝试3种相位的[0,1,2]循环模式
        // 第一种：a[i] = i%3
        // 第二种：a[i] = (i+1)%3
        // 第三种：a[i] = (i+2)%3

        auto check = [&](vector<int> &a) {
            for (int i = 1; i <= n; i++) {
                // 求 MEX
                // 收集朋友的值
                unordered_set<int> s;
                for (auto f : adj[i]) {
                    s.insert(a[f]);
                }
                int mexVal = 0;
                while (s.count(mexVal)) mexVal++;
                if (mexVal != a[i]) return false;
            }
            return true;
        };

        vector<int> a(n+1);
        bool found = false;

        for (int start = 0; start < 3 && !found; start++) {
            for (int i = 1; i <= n; i++) {
                a[i] = ( (i-1) + start ) % 3; 
            }

            if (check(a)) {
                found = true;
                break;
            }
        }

        // 理论上总能找到
        for (int i = 1; i <= n; i++) {
            cout << a[i] << (i == n ? '\n' : ' ');
        }
    }

    return 0;
}
