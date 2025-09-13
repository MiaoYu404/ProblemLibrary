#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 5;
int n, ans;
int a[maxn], pre[maxn];

void init() {
    memset(a, 0, sizeof(a));
    memset(pre, 0, sizeof(pre));
    ans = 0;
    cin >> n; 
    for (int i = 1; i <= n; i++) {
        int x; cin >> x; a[i] = x;
        pre[i] = pre[i - 1] + x;
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        init();

        for(int i = 1; i <= n; i++) {
            int x = sqrt(pre[i]);
            if(x % 2 == 0) continue;
            if(x * x == pre[i]) ans++;
        }

        cout << ans << endl;
    }
}