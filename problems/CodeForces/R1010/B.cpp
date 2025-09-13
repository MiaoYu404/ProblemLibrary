#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using ll = long long;

// const int MOD; // Not needed, as problem doesn’t require modulo

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    if (n == 2) {cout << a[0] + a[1] << endl; return;}
    if (k == 1) {
        ans = max(a[0], a[n - 1]);
        sort(a.begin() + 1, a.end() - 1, greater<ll>());
        cout << max(ans + a[1], a[0] + a[n - 1]) << endl;
    } else {
        sort(a.begin(), a.end(), greater<ll>());
        ll sum = 0;
        for (int i = 0; i <= k; i++) { // k+1 elements, indices 0 to k
            sum += a[i];
        }
        cout << sum << "\n"; // endl or \n both work, \n is slightly faster
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        solve();
    }
    return 0;
}