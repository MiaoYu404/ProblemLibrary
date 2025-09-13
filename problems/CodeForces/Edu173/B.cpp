#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int tt; cin >> tt; while (tt--) {
        int n, d; cin >> n >> d;
        cout << 1 << ' ';
        /*
        if (d % 2 == 0) {
            cout << 2 << ' ';
            if (n >= 3) cout << 4 << ' ' << 6 << ' ';
            if (d == 8) cout << 8 << ' ';
        }
        */
            if (n >= 3 or d % 3 == 0) cout << 3 << ' ';
            if (d == 5) cout << 5 << ' ';
            if (n >= 3 or d % 7 == 0) cout << 7 << ' ';
            if (n >= 6 or (n >= 3 and d % 3 == 0) or (d == 9)) cout << 9 << ' ';
        cout << '\n';
    }
    return 0;
}