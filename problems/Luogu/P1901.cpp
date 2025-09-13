#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 10;
ll V[N], H[N], E[N];

int main () {
    stack<int> stk;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int h, v; cin >> h >> v;
        H[i] = h, V[i] = v;
        if (stk.empty()) {
            stk.push(i); continue;
        }

        while (stk.size() && H[stk.top()] < H[i]) {
            E[i] += V[stk.top()];
            stk.pop();
        }
        if (stk.size()) {
            E[stk.top()] += V[i];
        }
        stk.push(i);
    }    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, E[i]);
    }
    cout << ans;
}