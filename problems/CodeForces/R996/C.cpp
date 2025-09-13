#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 10;
int n, m, x, y;
ll mp[N][N];

ll sum[3][N];
//bool vis[2][N];
void init() {
    for (int i = 1; i <= n; ++i) {
        sum[1][i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        sum[2][i] = 0;
    }
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int tt; cin >> tt; while (tt--) {
        cin >> n >> m;
        init();
        string s; cin >> s;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; ++j) {
                int val; cin >> val;
                sum[1][i] += val; sum[2][j] += val;
                mp[i][j] = val;
            }
        }

        x = 1; y = 1;
        for (auto ch : s) {
            if (ch == 'D') {
                mp[x][y] = sum[1][x] * (-1);
                sum[1][x] = 0;
                sum[2][y] += mp[x][y];
                x++;
            } else {
                mp[x][y] = sum[2][y] * (-1);
                sum[2][y] = 0;
                sum[1][x] += mp[x][y];
                y++;
            }
        }
        mp[x][y] = sum[2][y] * (-1);
        

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; ++j) {
                cout << mp[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}