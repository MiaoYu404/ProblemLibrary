// link: https://usaco.org/index.php?page=viewproblem2&cpid=1094

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, x, y) for (int i = x; i <= y; i++)
#define mp make_pair
#define fi first
#define se second

typedef unsigned long long ull;
typedef long long ll;

const int N = 1e3 + 5;

int n, m, q;
char grid[N][N];
pair<int, int> spec[N][N], dir[4]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int s_pre[N][N], v_pre[N][N], h_pre[N][N];
bool deleted[N][N];

bool inside(int x, int y, int nx, int ny) {
    if (!(nx >= 0 && nx <= n + 1 && ny >= 0 && ny <= m + 1)) return false;

    if (nx == x + 1) return grid[x][y] != grid[x][y - 1];   // down
    if (nx == x - 1) return grid[nx][y] != grid[nx][y - 1]; // up
    if (ny == y + 1) return grid[x][y] != grid[x - 1][y];   // right
    return grid[x][ny] != grid[x - 1][ny];                  // left
}

bool outside(int x, int y, int x1, int y1, int x2, int y2) {
    int a = spec[x][y].fi, b = spec[x][y].se;
    if (a > x1 && a <= x2 && b > y1 && b <= y2 && !deleted[a][b]) {
        deleted[a][b] = true;
        return true;
    }
    return false;
}

void deactive(int x, int y) {
    int a = spec[x][y].fi, b = spec[x][y].se;
    deleted[a][b] = false;
}

void dfs(int x, int y) {
    FOR(i, 0, 3) {
        int nx = x + dir[i].fi, ny = y + dir[i].se;
        if (inside(x, y, nx, ny)) {
            if (nx ==  x + 1) v_pre[x][y] = 1;
            else if (nx == x - 1) v_pre[nx][y] = 1;
            else if (ny == y + 1) h_pre[x][y] = 1;
            else h_pre[x][ny] = 1;

            if (!spec[nx][ny].fi) {
                spec[nx][ny] = spec[x][y];
                dfs(nx, ny);
            }
        }
    }
}

void solve()
{
    cin >> n >> m >> q;
    FOR(i, 1, n) FOR(j, 1, m) cin >> grid[i][j];
    FOR(i, 1, n + 1) FOR(j, 1, m + 1) if (!spec[i][j].first) {
        s_pre[i][j] = 1;
        spec[i][j] = {i, j};
        dfs(i, j);
    }

    FOR(i, 1, n + 1) FOR(j, 1, m + 1) {
        s_pre[i][j] += s_pre[i - 1][j] + s_pre[i][j - 1] - s_pre[i - 1][j - 1];
        v_pre[i][j] += v_pre[i - 1][j] + v_pre[i][j - 1] - v_pre[i - 1][j - 1];
        h_pre[i][j] += h_pre[i - 1][j] + h_pre[i][j - 1] - h_pre[i - 1][j - 1];
    }

    while (q--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);

        int E = v_pre[x2][y2] - v_pre[x2][y1] - v_pre[x1 - 1][y2] + v_pre[x1 - 1][y1] + 
                h_pre[x2][y2] - h_pre[x2][y1 - 1] - h_pre[x1][y2] + h_pre[x1][y1 - 1];
        int V = (x2 - x1) * (y2 - y1);
        int C = s_pre[x2][y2] - s_pre[x2][y1] - s_pre[x1][y2] + s_pre[x1][y1];

        FOR(i, x1, x2 + 1) {
            if (outside(i, y2 + 1, x1, y1, x2, y2)) C--;
            if (outside(i, y1, x1, y1, x2, y2)) C--;
        }
        FOR(i, y1, y2 + 1) {
            if (outside(x2 + 1, i, x1, y1, x2, y2)) C--;
            if (outside(x1, i, x1, y1, x2, y2)) C--;
        }
        FOR(i, x1, x2 + 1) {
            deactive(i, y2 + 1);
            deactive(i, y1);
        }
        FOR(i, y1, y2 + 1) {
            deactive(x2 + 1, i);
            deactive(x1, i);
        }

        cout << E - V + C + 1 << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    solve();

    return 0;
}

// 记得开 long long