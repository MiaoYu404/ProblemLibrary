#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

const int N = 3e2 + 10;
i64 mp[N][N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                i64 x; cin >> x;
                mp[i][j] = x;
            }
        }

        queue<int> present, next;
        for (int i = 1; i <= n; i++) {
            if (mp[i][n] == 1) present.push(i);
        }
        
        int row = n - 1;
        int left = n - 1;
        int ans = 1;
        while (row >= 1 and !present.empty() and left != 0) {
            
            while (!present.empty()) {
                int p = present.front(); present.pop();
                if (mp[p][row] == 1) {
                    next.push(p);
                }
            }
            int cnt = 0;
            while (!next.empty()) {
                present.push(next.front()); next.pop();
                cnt++;
            }
            left = min(left - 1, cnt);
            ans++;
            row--;
        }
        
        cout << ans << endl;
    }

    return 0;
}