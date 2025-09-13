#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using ll = long long;

const int MOD = 1e9 + 7;

bool can_reach(vector<double>& a, double x, int n) {
    if (n == 1) {
        return abs(a[0] - x) < 1e-9;
    }
    
    for (int k = 1; k < n; k++) {
        if (n % k != 0) continue;
        
        int len = n / k;
        vector<vector<double>> subs(k);

        vector<double> sorted = a;
        sort(sorted.begin(), sorted.end());
        
        for (int i = 0; i < n; i++) {
            subs[i % k].pb(sorted[i]);
        }
        
        vector<double> next;
        for (int i = 0; i < k; i++) {
            double sum = 0;
            for (double val : subs[i]) {
                sum += val;
            }
            next.pb(sum / len);
        }
        
        if (can_reach(next, x, k)) {
            return true;
        }
    }
    
    return false;
}

void solve() {
    int n, x;
    cin >> n >> x;
    
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    if (can_reach(a, x, n)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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