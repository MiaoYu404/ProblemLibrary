#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int tt; cin >> tt; while (tt--) {
        double n, k, l;
        cin >> n >> k >> l;
        vector<double> a, b;
        for (int i = 1; i <= n; ++i) {
            int x; cin >> x; a.push_back(x);
        }
        double T = a[0];
        b.push_back(0);
        for (int i = 1; i < n; ++i) {
            double case1 = (a[i] - T + b[i - 1] + k) / 2.0;
            double case2 = b[i - 1] + k;
            double case3 = a[i] + T;
            double tmp = min(l, min(case3, max(case1, case2)));

            b.push_back(tmp);
            if (case1 > case2) T += (case1 - case2);
        }
        b.push_back(l);
        double d = 0;
        for (int i = 1; i <= n; ++i) {
            d += min(k, b[i] - b[i - 1]);
        }
        cout << (int)round((a[0] + l - d)*2) << endl;
    }
    return 0;
}