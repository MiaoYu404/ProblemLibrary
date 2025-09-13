#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int tt; cin >> tt; while (tt--) {
        string s; cin >> s;
        int a = s[0] - '0', b = s[2] - '0';
        if (a > b) cout << a << ">" << b << endl;
        else if (a == b) cout << a << "=" << b << endl;
        else cout << a << "<" << b << endl;
    }
}