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
        vector<int> num(n + 1);
        for (int i = 1; i <= n; i++) {
            int x; cin >> x; num[i] = x;
        }

        bool flag = false;
        int i = 1;
        for (; i <= n; i++) {
            if (num[i] != 0) {flag = true; break;}
        }
        if (!flag) {
            cout << 3 << endl;
            cout << 1 << " " << 2 << endl;
            cout << 2 << " " << n - 1 << endl;
            cout << 1 << " " << 2 << endl;
            continue;
        }

        if (num[1] == 0) {
            flag = false; i = n; for (;i > 1; i--) if (num[i] == 0) {flag = true; break;}
            if (flag) { 
                if (i == n) {
                    cout << 3 << endl;
                    cout << 3 << " " << n << endl;
                    cout << 1 << " " << 2 << endl;
                    cout << 1 << " " << 2 << endl;
                } else if (i == 2) {
                    cout << 2 << endl;
                    cout << 1 << " " << 2 << endl;
                    cout << 1 << " " << n - 1 << endl;
                } else {
                    cout << 3 << endl;
                    cout << i << " " << n << endl;
                    cout << 1 << " " << i - 1 << endl;
                    cout << 1 << " " << 2 << endl;
                }
            } else {
                cout << 2 << endl;
                cout << 1 << " " << 2 << endl;
                cout << 1 << " " << n - 1 << endl;
            }
            continue;
        } else {
            // num[1] == something;
            flag = false; i = n; for (;i > 1; i--) if (num[i] == 0) {flag = true; break;}
            if (flag) {   // found 0
                cout << 2 << endl;
                cout << 2 << " " << n << endl;
                cout << 1 << " " << 2 << endl;
            } else {
                cout << 1 << endl;
                cout << 1 << " " << n << endl;
            }
            continue;
        }
    }
    return 0;
}