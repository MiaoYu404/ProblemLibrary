#include <bits\stdc++.h>

using namespace std;
using ll = long long;

int main () {
    int tt; cin >> tt; while (tt--) {
        int n, x, y;
        cin >> n >> x >> y;
        int num = 0;
        vector<int> a;
        bool b1 = false;
        if (x % 2 == y % 2) b1 = true;
        for (int i = 1; i < n; i++) {
            if (i == y and b1) {cout << 2 << " "; a.push_back(2); num = 0;}
            else {
                cout << num << " ";
                a.push_back(num);
                num = (num + 1) % 2;
            }
        }
        
        bool v[5];
        memset(v, false, sizeof(v));
        if (y == n) v[a[x - 1]] = true;
        v[a[0]] = true; v[a[n - 2]] = true;
        int ans = 0;
        while (v[ans]) ans++;
        cout << ans << '\n';
    }
    return 0;
}
