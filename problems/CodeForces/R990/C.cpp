#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e3 + 10;
int n, t;
int a[maxn][2];
int ans;

void init() {
    ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        a[i][0] = x;
    }
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        a[i][1] = x;
    }
}

int main() {
    cin >> t; while(t--) {
        init();
        int M = INT_MIN;
        for(int i = 1; i <= n; i++) {
            ans += max(a[i][0], a[i][1]);
            M = max(min(a[i][0], a[i][1]), M);
        }
        ans += M;
        cout << ans << endl;
    }
}