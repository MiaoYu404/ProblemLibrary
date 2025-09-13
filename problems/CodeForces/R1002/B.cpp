#include <bits/stdc++.h>
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;
 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

typedef long long ll;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto &it: a) cin >> it;
    k /= 2;
    if (k * 2 == n) {
        for (int i = 1; i < n; i += 2) {
            if (a[i] != (i + 2) / 2) {
                cout << (i + 2) / 2 << endl;
                return ;
            }
        }
        cout << k + 1 << endl; return ;
    } else {
        for (int i = 1; i < n - 2 * k + 2; i++) {
            if (a[i] != 1) {
                cout << 1 << endl;
                return ;
            }
        }
        cout << 2 << endl; return ;
    }

}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt; cin >> tt; while (tt--) {
        solve();
    }

    return 0;
}