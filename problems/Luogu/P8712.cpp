// P8712 [蓝桥杯 2020 省 B1] 整数拼接
// tags: 哈希
// 难度: 普及 / 提高-
// link: https://www.luogu.com.cn/problem/P8712

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
unordered_map<ll, int> m[11];
vector<int> num;

int main () {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        num.push_back(x);
        ll key = x % k;
        for (int i = 0; i <= 10; i++) {
            m[i][key]++;
            key = key * 10 % k;
        }
    }

    ll ans = 0;
    for (auto x : num) {
        ll t = x % k;
        int len = to_string(x).size();

        ans += m[len][(k - t) % k];
        ll cmp = t;
        while (len--) {
            cmp = cmp * 10 % k;
        }
        if (cmp == (k - t) % k) ans--;
    }

    cout << ans;
    return 0;
}