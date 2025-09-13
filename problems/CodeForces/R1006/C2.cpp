#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tt; cin >> tt; while (tt--) {
        int n; ll x;
        cin >> n >> x;
        vector<ll> a;

        ll y = 0; bool flag = false;
        ll presen = 0;

        while (a.size() < n) {
            if (a.size() == n - 1) {
                if (presen == x or (presen | y) == x) {
                    if ((y & x) == y) {
                        a.push_back(y);
                        presen |= y;
                    } else flag = true;
                    
                    if (flag) a.push_back(0);
                } else a.push_back(x);
                
                break;
            }
            if ((y & x) == y) {
                a.push_back(y);
                presen |= y;
                y++;
            } else flag = true;
            
            if (flag) a.push_back(0);
        }
        // 输出数组
        for (int i = 0; i < n; ++i) {
            if (i > 0) cout << " ";
            cout << a[i];
        }
        cout << "\n";
    }
    return 0;
}