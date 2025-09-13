#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int tt; cin >> tt; while (tt--) {
        ll n; cin >> n;
        ll ans = 1;
        n /= 4;
        while (n != 0) {n /= 4; ans *= 2;}
        cout << ans << '\n';
    }
    return 0;
}