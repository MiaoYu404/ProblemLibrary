#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int T; cin >> T;
    while(T--) {
        ll x; ll m; cin >> x >> m;
        ll p = m - m % x;
        ll c1 = p / x - (x < p);
        //cout << c1 << endl;
        if((x ^ p) >= 1 and (p ^ x) <= m) c1++;
        p += x;
        if((x ^ p) >= 1 and (p ^ x) <= m) c1++;

        int c2 = 0;
        for (int y = 1; y <= min(x, m); y++) {
            int p = x xor y;
            if (p % y == 0) c2++;
        }
        int c3 = 0;
        if(x <= m) c3 = 1;
        cout << c1 + c2 - c3 << endl;
    }
}