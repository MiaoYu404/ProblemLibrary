#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e3 + 10;
ll f[N][N];

int main() {
    int tt; cin >> tt; while (tt--) {
        string a, b, c;
        cin >> a >> b >> c;
        int lenA = a.length();
        int lenB = b.length();
        for (int i = 0; i <= lenA; i++) {
            for (int j = 0; j <= lenB; j++) {
                f[i][j] = 0;
            }
        }

        f[0][0] = 0;
        for (int i = 0; i <= lenA; i++) {
            if (i != 0) f[i][0] = c[i - 1] == a[i - 1]? f[i - 1][0] : f[i - 1][0] + 1LL;
            for (int j = 1; j <= lenB; j++) {
                f[i][j] = min(
                    c[i + j - 1] == b[j - 1] ? f[i][j - 1] : f[i][j - 1] + 1LL,
                    i != 0 ? (c[i + j - 1] == a[i - 1] ? f[i - 1][j] : f[i - 1][j] + 1LL) : N
                );
            }
        }
        cout << f[lenA][lenB] << '\n';
    }
    return 0;
}