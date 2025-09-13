#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
    int T; cin >> T;
    while (T--) {
        int x; ll m; cin >> x >> m;
        int cnt = 0;
        for (int y = 1; y <= min(2LL * x - 1, m); y++){
            if (x == y) continue;
            int z = x ^ y;
            if( x % z == 0 or y % z == 0) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}