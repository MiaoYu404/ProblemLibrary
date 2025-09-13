// Educational Codeforces Round 179 (Rated for Div. 2) C. Equal Values
// tag: 暴力
// 难度: 未给
// link: https://codeforces.com/contest/2111/problem/C

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using ll = long long;

const int MOD = 1e9 + 5;
const int N = 5e5 + 10;

int cnt[N], a[N];
void solve() {
    int n; cin >> n;
    int maxn = -1, minn = N;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x; a[i] = x;
        maxn = max(x, maxn);
        minn = min(x, minn);
    }
    int last = a[1], tmp = 1;
    cnt[last] = 1;
    for (int i = 2; i <= n; i++) {
        // if (last == -1) {last = a[i]; tmp++; continue;}

        if (last == a[i]) {
            tmp++;
        } else {    // last != a[i]
            tmp = 1; last = a[i];
        }
        cnt[last] = max(cnt[last], tmp);
    }
    ll cost = (ll)(n - 1) * (ll)minn;
    for (int i = minn; i <= maxn; i++) {
        if(cnt[i] < 2) continue;
        ll c = n - cnt[i];
        c *= i;
        cost = min(cost, c);
    }
    cout << cost << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt; cin >> tt; while (tt--) {
        solve();
        memset(cnt, 0, sizeof(cnt));
    }
    
    return 0;
}

// 记得开 long long