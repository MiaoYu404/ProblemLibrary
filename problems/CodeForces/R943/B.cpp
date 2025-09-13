#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt; while (tt--) {
        int n, m; cin >> n >> m;
        int a[N], b[N];
        for (int i = 1; i <= n; i++) {
            char ch; cin >> ch;
            a[i] = ch - '0';
        }
        for (int i = 1; i <= m; i++) {
            char ch; cin >> ch;
            b[i] = ch - '0';
        }

        // 状态压缩，压缩成连续 n 个 1 和 连续 m 个 0 这样 开一个队列 不断拿 直到拿完；
    }
    return 0;
}