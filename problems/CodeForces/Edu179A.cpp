// Educational Codeforces Round 179 (Rated for Div. 2) A. Energy Crystals
// tag: bitwise
// 难度: 未给
// link: https://codeforces.com/contest/2111/problem/B

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using ll = long long;

const int MOD = 1e9 + 5;

void solve() {
    int x; cin >> x; int ans = 1;
    if (x == 0) {cout << 0 << endl; return ;}

    while (x != 0) {
        x = x >> 1;
        ans += 2;
    }
    cout << ans << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt; cin >> tt; while (tt--) {
        solve();
    }

    return 0;
}

// 记得开 long long