// AcWing 998. 起床困难综合症

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using ll = long long;

const int MOD = 20000101;
const int N = 1e5 + 10;

int ans[N];
int n, m;

int rsl[30][2];
vector< pair<int, int> > ops;

int cal (int x, int i) {
    for (auto p : ops) {
        int op = p.first, t = p.second;
        int b = (t >> i) & 1;
        if (op == 1) x &= b;
        if (op == 2) x |= b;
        if (op == 3) x ^= b;
    }
    return x << i;
}

void solve () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string op; int t;
        cin >> op; cin >> t;
        if (op == "AND") ops.push_back(make_pair(1, t));
        else if (op == "OR") ops.push_back(make_pair(2, t));
        else ops.push_back(make_pair(3, t));
    }
    
    int ans = 0, tmp = 0;
    for (int i = 29; i >= 0; i--) {
        int cal0 = cal(0, i);
        int cal1 = cal(1, i);

        if ((tmp + (1 << i)) <= m and cal0 < cal1) {
            ans += cal1;
            tmp += (1 << i);
        } else {
            ans += cal0;
        }
    }
    cout << ans << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    solve();

    return 0;
}

// 记得开 long long