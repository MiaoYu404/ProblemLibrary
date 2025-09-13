#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

int main () {
    int tt; cin >> tt; while (tt--) {
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        map<ll, vector<ll> > adj;
        for (int i = 1; i < n; i++) {
            ll u = a[i] + i;
            ll v = u + i;
            adj[u].push_back(v);
        }

        set<ll> vis;
        function<void(ll)> dfs = [&](ll u) -> void {
            if (vis.count(u)) return;
            vis.insert(u);
            for (ll v : adj[u]) dfs(v);
        };
        dfs(n);
        cout << *vis.rbegin() << "\n";
    }
}