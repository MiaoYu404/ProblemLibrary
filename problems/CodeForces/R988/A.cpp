#include <bits/stdc++.h>
using namespace std;

const int N = 2e1 + 5;

int a[N];

int main() {
    int t; cin >> t;
    while(t--) {
        int ans = 0;
        memset(a, 0, sizeof(a));

        int n; cin >> n;
        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            a[x] ++;
        }

        for(int i = 1; i <= n; i++) {
            ans += a[i] / 2;
        }

        cout << ans << endl;
    }

    return 0;
}