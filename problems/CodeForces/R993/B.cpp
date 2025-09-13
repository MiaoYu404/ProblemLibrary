#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int tt, n;

int main() {
    cin >> tt; while (tt--) {
        string s; cin >> s;
        for (int i = s.length() - 1; i >= 0; i--) {
            char x = s[i];
            if (x == 'p') x = 'q';
            else if (x == 'q') x = 'p';
            cout << x;
        }
        cout << '\n';
    }
    return 0;
}