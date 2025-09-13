#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using ll = long long;

const int MOD = 1e9 + 7;

class FenwickTree {
private:
    vector<int> tree;
    int n;
public:
    FenwickTree(int size) : n(size) {
        tree.assign(n + 1, 0);
    }
    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            tree[idx] += val;
        }
    }
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }

    int countGreater(int x) {
        if (x >= n) return 0;
        return query(n) - query(x);
    }
};

void solve () {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<vector<ll>> inv(n + 1, vector<ll>(n + 1, 0));
    for (int p = 1; p <= n; ++p) {
        FenwickTree ft(2000);
        ll current_inv = 0;
        for (int q = p; q <= n; ++q) {
            if (q > p) {
                int num_greater = ft.countGreater(a[q]);
                current_inv += num_greater;
            }
            inv[p][q] = current_inv;
            ft.update(a[q], 1);
        }
    }

    ll min_delta = 1e18;
    int best_l = 1, best_r = 1;
    for (int l = 1; l <= n; ++l) {
        ll s = 0;
        for (int r = l; r <= n; ++r) {
            ll delta;
            if (r == l) {
                delta = 0;
            } else {
                if (a[r] > a[l]) {
                    s += 1;
                }
                ll inv_shifted = (l + 1 <= r ? inv[l + 1][r] : 0) + s;
                delta = inv_shifted - inv[l][r];
            }
            if (delta < min_delta) {
                min_delta = delta;
                best_l = l;
                best_r = r;
            }
        }
    }

    cout << best_l << " " << best_r << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt; while (tt--) {
        solve();
    }
    return 0;
}