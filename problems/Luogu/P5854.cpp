#include <bits/stdc++.h>
using namespace std;
using ll = long long;

stack<int> stk;
const int N = 1e7 + 10;
ll w[N], ls[N], rs[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n; cin >> n;
    
    memset(ls, 0, sizeof(ls));
    memset(rs, 0, sizeof(rs));
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x; w[i] = x;
    }
    
    for (int i = 1; i <= n; ++i)
    {
        int flag = 0; // top 表示操作前的栈顶，k 表示当前栈顶
        while (stk.size() && w[stk.top()] > w[i])
           flag = stk.top(), stk.pop(); // 维护右链上的结点
        if (stk.size()) rs[stk.top()] = i;
        if (flag) ls[i] = flag;
        stk.push(i);
    }

    ll ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) {
        ans1 ^= 1LL * (i * (ls[i] + 1));
        ans2 ^= 1LL * (i * (rs[i] + 1));
    }
    cout << ans1 << " " << ans2;
}