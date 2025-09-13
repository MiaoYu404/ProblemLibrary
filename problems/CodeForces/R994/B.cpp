#include <bits\stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int tt; cin >> tt; while (tt--) {
        int n; string s;
        cin >> n >> s;
        int P = n + 1, S = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == 's') S = i;
            if (s[i - 1] == 'p' and P == n + 1) P = i;
        }
        //cout << S <<" " << P << endl;
        if (P + 1 < n + 1 and S - 1 > 0) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    return 0;
}