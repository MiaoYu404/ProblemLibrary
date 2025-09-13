#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int m = 2 * n;
    vector<long long> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    // 降序排序
    sort(b.rbegin(), b.rend());
    long long x = 0;
    // 计算偶数项的和减去奇数项的和
    for (int i = 0; i < n - 1; ++i) {
        x += b[2 * (i + 1)] - b[2 * i + 1];
    }
    x -= b[2 * n - 1];
    // 构造结果
    cout << b[0] << " " << b[0] - x << " ";
    for (int i = 1; i < m; ++i) {
        cout << b[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}