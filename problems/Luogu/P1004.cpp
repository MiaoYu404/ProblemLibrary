#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

const int N = 10;
bool vis[N][N][N][N];
int dp[N][N][N][N];
int mp[N][N];
struct info {
    int a, b, c, d;
    info(int a, int b, int c, int d) :a(a), b(b), c(c), d(d){}
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n; cin >> n;
    int x, y, val;
    cin >> x >> y >> val;
    while (x != 0 and y != 0 and val != 0) {
        mp[x][y] = val;
        cin >> x >> y >> val;
    }

    for (int a = 1; a <= n; a++) for (int b = 1; b <= n; b++) for (int c = 1; c <= n; c++) for (int d = 1; d <= n; d++) vis[a][b][c][d] = false;

    // dp[a][b][c][d] = max(
    // dp[a - 1][b][c - 1][d]
    // dp[a - 1][b][c][d - 1]
    // dp[a][b - 1][c - 1][d]
    // dp[a][b - 1][c][d - 1]
    // ) + mp[a][b] + mp[c][d];
    // if (a == c and b == d) -= mp[a][b];

    queue<info> q;
    q.push(info(1, 1, 1, 1));
    while (!q.empty()) {
        info x = q.front(); q.pop();
        int a = x.a, b = x.b, c = x.c, d = x.d;
        int rsl = 0;
        rsl = max(rsl, dp[a - 1][b][c - 1][d]);
        rsl = max(rsl, dp[a - 1][b][c][d - 1]);
        rsl = max(rsl, dp[a][b - 1][c - 1][d]);
        rsl = max(rsl, dp[a][b - 1][c][d - 1]);
        if (a == c and b == d) dp[a][b][c][d] = rsl + mp[a][b];
        else dp[a][b][c][d] = rsl + mp[a][b] + mp[c][d];

        if (a == n and b == n and c == n and d == n) break;
        if (a != n) {
            if (c != n) if (!vis[a + 1][b][c + 1][d]) q.push(info(a + 1, b, c + 1, d));
            if (d != n) if (!vis[a + 1][b][c][d + 1]) q.push(info(a + 1, b, c, d + 1));
        }
        if (b != n) {
            if (c != n) if (!vis[a][b + 1][c + 1][d]) q.push(info(a, b + 1, c + 1, d));
            if (d != n) if (!vis[a][b + 1][c][d + 1]) q.push(info(a, b + 1, c, d + 1));
        }
        vis[a + 1][b][c + 1][d] = vis[a + 1][b][c][d + 1] = vis[a][b + 1][c + 1][d] = vis[a][b + 1][c][d + 1] = true;
    }
    cout << dp[n][n][n][n] << endl;
    return 0;
}