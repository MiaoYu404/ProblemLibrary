#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using ll = long long;

const int MOD = 1e9 + 5;

int n, m;
int find (int pre, int x, vector<int> b) {
    // pre le b[some] - x
    int target = pre + x;
    int rsl = -1;
    int l = 0, r = m - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (b[mid] >= target) r = mid;
        else l = mid + 1;
    }
    if (b[l] < target) return -1;
    else return l;
}

void solve () {
    cin >> n >> m;
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x; a.pb(x);
    }
    for (int i = 1; i <= m; i++) {
        int x; cin >> x; b.pb(x);
    }

    sort(b.begin(), b.end());

    bool flag = true;
    a[0] = min(b[m - 1] - a[0], a[0]);
    for (int i = 1; i < n; i++) {
        // min(a[1], b[i] - a[1]) ge a[0];
        int index = find(a[i - 1], a[i], b);
        int cmp = a[i];
        if (cmp >= a[i - 1]) {
            if (index != -1) a[i] = min(a[i], b[index] - a[i]);
        }
        else {
            if (index == -1) {flag = false; break;}
            a[i] = b[index] - a[i];
        }
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt; cin >> tt; while (tt--) {
        solve();
    }
    return 0;
}