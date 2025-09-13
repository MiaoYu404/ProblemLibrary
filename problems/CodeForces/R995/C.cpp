#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int tt; cin >> tt; while (tt--) {
        int n, m, k;
        cin >> n >> m >> k;
        bool flag = true; if (k < n - 1) flag = false;
        vector<int> q;
        for (int i = 1; i <= m; i++) {
            int x; cin >> x;
            q.push_back(x);
        }

        int Min = 1;
        for (int i = 1; i <= k; i++) {
            int x; cin >> x; if (x == Min) Min++;
        }
        
        if (n == k) {
            for (int i = 1; i <= m; i++) {
                cout << 1;
            }
            cout << '\n';
            continue;
        } else if (!flag) {
            for (int i = 1; i <= m; i++) {
                cout << 0;
            }
            cout << '\n';
            continue;
        } else {
            for (auto x : q) {
                if (x == Min) cout << 1;
                else cout << 0;
            }
            cout << endl;
        }
    }
}