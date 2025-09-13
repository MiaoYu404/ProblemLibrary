/*
user: MiaoYu404
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using ll = long long;

const int MOD = 1e9 + 5;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        if (s[0] == 'A' and s[n - 1] == 'A') {
            cout << "Alice" << endl;
            continue;
        } else if (s[0] != 'A' and s[n - 1] == 'A') {
            if (s[n - 2] == 'A') {
                cout << "Alice" << endl;
            } else {
                cout << "Bob" << endl;
            }
            continue;
        } else if (s[0] == 'A' and s[n - 1] != 'A') {
            bool flag = false;
            for (int i = 1; i < n - 1; i++) {
                if (s[i] != 'A') {flag = true; break;}
            }
            if (!flag) {cout << "Alice" << endl;}
            else cout << "Bob" << endl;
            continue;
        } else {
            cout << "Bob" << endl;
            continue;
        }
    }
    return 0;
}