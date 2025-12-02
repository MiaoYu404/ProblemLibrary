#include <bits/stdc++.h>

using namespace std;

int n, m;
//上下左右
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int maxn = 1e4 + 10;

int sx = 0, sy = 0;
int ex = 0, ey = 0;

queue< array<int, 5> > q;

template <typename T>
    void chkmn(T &x, T y) {x = min(x, y); }

int main () {
    cin >> n >> m;
    int dis[n][m][4][3] = {};         //x，y，四个方向，3步
    char mp[n][m] = {};
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == 'S') {sx = i; sy = j;}
            if (mp[i][j] == 'T') {ex = i; ey = j;}
        }
    }
    array<int, 5> tmp = {sx, sy, -1, -1, 0};
    q.push(tmp);

    auto in = [&] (int x, int y) {return 1 <= x && x <= n && 1 <= y && y <= m;};

    int ans = 1e9;

    while (!q.empty()) {
        auto [x, y, d, c, ds] = q.front();
        q.pop();
        if (x == ex && y == ey)
            chkmn(ans, ds);
        
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (i == d && c == 2) continue; // 同方向走到底

            if (in(tx, ty) && mp[tx][ty] != '#') //不是墙
            {
                array<int, 5> tmp = {tx, ty, i, (i == d ? c + 1 : 0), ds + 1};
                //dis[tx][ty][i][(i == d ? c + 1 : 0) 方向 i 上是否与来时同向。第c+1步；第1步。
                //是否最优？dijkstra
                if (dis[tx][ty][i][(i == d ? c + 1 : 0)] > ds + 1)
                    dis[tx][ty][i][(i == d ? c + 1 : 0)] = ds + 1, q.push(tmp);
            }
        }
    }

    cout << (ans == 1e9 ? -1 : ans) << '\n';
    return 0;
}