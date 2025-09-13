#include <bits/stdc++.h>
using namespace std;

int main () {
    int L, n; vector<int> a;
    cin >> L >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x; a.push_back(x);
    }
    sort(a.begin(), a.end());
    int rsl1 = 0, rsl2 = 0;
    for (int i = 0; i < n; i++) {
        int val1 = a[i], val2 = L + 1 - a[i];
        rsl1 = max(rsl1, min(val1, val2));
        rsl2 = max(rsl2, max(val1, val2));
    }
    cout << rsl1 << " " << rsl2;
}