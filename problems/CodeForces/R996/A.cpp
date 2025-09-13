#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int tt; cin >> tt; while (tt--) {
        int n, a, b; cin >> n >> a >> b;
        if (a > b) swap(a, b);
        if ((b - a - 1)% 2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}