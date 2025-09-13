#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int m, n;
int a[N], f[N][20];

void ST_init() {
    for (int i = 1; i <= m; i++) {memset(f[i], 0x3F, sizeof(f[i])); f[i][0] = a[i];}
    int t = log(m) / log(2);
    for (int j = 1; j <= t; j++) {
        for (int i = 1; i <= m - (1 << j) + 1; i++) {
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int ST_query(int l, int r) {
    int k = log2(r - l + 1);
    return min(f[l][k], f[r - (1 << k) + 1][k]);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        a[i] = x;
    }

    ST_init();
    /*
    for (int i = 1; i <= m; i++) {
        for (int k = 0; k < 4; k++) cout << f[i][k] << ' ';
        cout << endl;
    }
    */

    while (n--) {
        int l, r; cin >> l >> r;
        cout << ST_query(l, r) << ' ';
    }
    return 0;
}