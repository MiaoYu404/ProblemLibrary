#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
ll H[N], ls[N], rs[N];
ll ans;
bool vis[N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n; cin >> n;
    while (n) {
        stack<ll> stk;
        ans = 0;
        stk.push(0); H[0] = 0;
        for (int i = 1; i <= n + 1; i++) {
            if (i < n + 1) cin >> H[i];
            else H[i] = 0;
            while (stk.size() && H[stk.top()] > H[i]) {
                int top = stk.top();
                stk.pop();
                ans = max(ans, H[top] * (i - stk.top() - 1));
            }
            stk.push(i);
        }
        cout << ans << endl;
        
        cin >> n;
    }
}