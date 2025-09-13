#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using ll = long long;

int pre[25];
void solve () {
    ll x, y;
    cin >> x >> y;
    if (x == y) {
        cout << 0 << endl; return;
    }
    if ((x == 2 and y == 3) or (x == 3 and y == 2)) {
        cout << 12 << endl; return;
    }

    deque<int> xq, yq;
    //if (x == 0) xq.push_front(0);
    while (x != 0) {
        xq.push_front(x % 2);
        x /= 2;
    }
    //if (y == 0) yq.push_front(0);
    while (y != 0) {
        yq.push_front(y % 2);
        y /= 2;
    }

    while (xq.front() == yq.front() and !xq.empty() and !yq.empty()) {
        xq.pop_front(), yq.pop_front();
    }
    int ans1 = 0, ans2 = 0;
    while (!xq.empty()) {xq.pop_front(); ans1++;}
    while (!yq.empty()) {yq.pop_front(); ans2++;}
    int ans = 0;
    for (int i = 1; i <= 20; i++) {
        if (ans1 + ans2 < pre[i]) {ans = i; break;}
    }
    int sub = pre[ans] - (ans1 + ans2);
    int output = 0;
    for (int i = 1; i <= ans; i++) {
        if (i == sub) continue;
        output += pow(2, i);
    }
    cout << output << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    pre[0] = 0;
    for (int i = 1; i <= 20; i++ ) {
        pre[i] = pre[i - 1] + i;
    }
    int t; cin >> t; while (t--) {
        solve();
    }
    return 0;
}