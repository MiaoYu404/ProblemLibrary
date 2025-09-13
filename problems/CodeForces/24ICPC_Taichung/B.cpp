#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int T; cin >> T;
    while(T--) {
        ll b, w; cin >> b >> w;
        ll tot = b + w;

        ll l = 1, r = 1e5;
        while(l < r) {
            ll mid = (l + r) / 2;
            ll val = mid * (mid + 1) / 2;
            //cout << mid * (mid + 1) << endl;
            if (val < tot) l = mid + 1;
            else r = mid;
        }
        if (l * (l + 1) / 2 > tot) l--;
        cout << l << endl;
    }
}