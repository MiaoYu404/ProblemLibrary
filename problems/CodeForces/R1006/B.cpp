#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
char a[N];
int b[N];
int pre[N];

void solve() {
    int n; cin >> n;
    cin >> a;
    // - 0, _ 1;
    for (int i = 0; i < n; i++) {
        b[i + 1] = (a[i] == '-' ? 0 : 1);
    }
    int cnt0 = 0, cnt1 = 0;
    for (int i = n; i >= 1; i--) {
        if (b[i] == 1) {
            cnt1 ++;
            pre[i] = cnt0;
        } else {
            cnt0 ++;
            pre[i] = cnt1;
        }
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += pre[i];
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