#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int tt, n;

int main() {
    cin >> tt; while (tt--) {
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        int left = 2 * m;
        left -= min(a, m);
        left -= min(b, m);
        left -= min(left, c);
        cout << 2 * m - left << endl;
    }
    return 0;
}