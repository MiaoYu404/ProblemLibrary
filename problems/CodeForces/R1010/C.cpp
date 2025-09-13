#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using ll = long long;

// Note: MOD is declared but not defined in the template; problem doesn't require it
// const int MOD;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    
    // Count frequency of each a_i
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < m; i++) {
        if (a[i] >= 1 && a[i] <= n) { // Always true given constraints, but kept for safety
            cnt[a[i]]++;
        }
    }
    
    // Compute A[s] = number of colors with a_i >= s
    vector<ll> A(n + 1, 0);
    A[n] = cnt[n];
    for (int s = n - 1; s >= 1; s--) {
        A[s] = A[s + 1] + cnt[s];
    }
    
    // Calculate total number of ways
    ll ans = 0;
    for (int k = 1; k <= n - 1; k++) {
        int nk = n - k;
        int m_val = max(k, nk); // max(k, n-k)
        ll ways = A[k] * A[nk]; // Total pairs including i = j
        ways -= A[m_val];       // Subtract cases where i = j
        ans += ways;
    }
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    
    return 0;
}