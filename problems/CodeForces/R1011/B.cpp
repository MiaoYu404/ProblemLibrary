#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using ll = long long;

const int MOD = 1e9 + 5;
const int N = 2e5 + 10;

int ans[N];
ll fen[N];
int n;
void upd(int x) {
    while (x <= n) {
        fen[x] ++;
        x += x & -x;
    }
}
ll que(int x) {
    ll ans = 0;
    while (x) {
        ans += fen[x];
        x -= x & -x;
    }
    return ans;
}

ll f(vector<int> x) {
    for (int i = 0; i <= n; i++) fen[i] = 0;
    ll ans = 0;
    for (int i = x.size() - 1; i >= 0; i--) {
        ans += que(x[i]);
        upd(x[i]);
    }

    return ans;
}

void solve() {
    cin >> n;
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (i % 2) a.pb(x);
        else b.pb(x);
    }

    bool flag = false;
    if (f(a) % 2 != f(b) % 2) {
        flag = true;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int xa = 0, xb = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2) {ans[i] = a[xa]; xa++;}
        else {ans[i] = b[xb]; xb++;}
    }

    if (flag) {
        int tmp = ans[n - 2]; ans[n - 2] = ans[n]; ans[n] = tmp;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt; cin >> tt; while (tt--) {
        solve();
    }
    return 0;
}