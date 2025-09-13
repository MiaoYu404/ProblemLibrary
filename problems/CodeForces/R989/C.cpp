#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 10;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string c[n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
            c[i] = "-" + c[i];
        }
        vector<pair<int, int> > jda[n + 2][m + 2];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (c[i][j] == 'U') jda[i - 1][j].push_back({i, j});
                if (c[i][j] == 'R') jda[i][j + 1].push_back({i, j});
                if (c[i][j] == 'D') jda[i + 1][j].push_back({i, j});
                if (c[i][j] == 'L') jda[i][j - 1].push_back({i, j});
            }
        }
        int vis[n + 2][m + 2];
        for (int i = 0; i <= n + 1; i++)
            for (int j = 0; j <= m + 1; j++)
                vis[i][j] = 0;
        
        queue<pair<int, int> > q;
        // 围个框
        for (int j = 0; j <= m + 1; j++) vis[0][j] = 1, q.push({0, j});
        for (int i = 1; i <= n + 1; i++) vis[i][0] = 1, q.push({i, 0});
        for (int j = 1; j <= m + 1; j++) vis[n + 1][j] = 1, q.push({n + 1, j});
        for (int i = 1; i <= n; i++) vis[i][m + 1] = 1, q.push({i, m + 1});
        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();
            for (auto [a, b] : jda[i][j])
            {
                if (!vis[a][b])
                {
                    vis[a][b] = 1;
                    q.push({a, b});
                }
            }
        }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (c[i][j] == '?' and vis[i - 1][j] and vis[i][j + 1] and vis[i + 1][j] and vis[i][j - 1])
                    vis[i][j] = 1;

        int ans = n * m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (vis[i][j] == 1)
                    ans--;
        cout << ans << endl;
    }
}