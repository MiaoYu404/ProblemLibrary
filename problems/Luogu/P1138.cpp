#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main () {
    int n, k;
    cin >> n >> k;
    set<int> a;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x; a.insert(x);
    }

    int cnt = 0, ans = 0;
    for (int i = 1; i <= 3e4; i++) {
        if (a.count(i)) {
            cnt++; ans = i;
            if (cnt == k) break;
        }
    }
    if (cnt < k) cout << "NO RESULT" << endl;
    else cout << ans << endl;
}