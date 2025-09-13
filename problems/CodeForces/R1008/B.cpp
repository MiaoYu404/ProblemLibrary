#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using ll = long long;

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n + 1); // 1-based indexing
    for (int i = 1; i < n - 1; i++) {
        if (k % 2 == 0) a[i] = n - 1;    // point to next cell
        else a[i] = n;
    }
    a[n - 1] = n;
    a[n] = n - 1;
    
    // Output result (1-based)
    for (int i = 1; i <= n; i++) {
        cout << a[i];
        if (i < n) cout << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}