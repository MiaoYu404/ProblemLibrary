#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int tt; cin >> tt; while (tt--) {
        int n, m;
        ll k;
        cin >> n >> m >> k;
        vector<vector<ll>> a(n, vector<ll>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        // 构建每行的前缀和(2*m)以支持旋转区间求和
        vector<vector<ll>> pre(n, vector<ll>(2 * m + 1, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2 * m; j++)
            {
                pre[i][j + 1] = pre[i][j] + a[i][j % m];
            }
        }

        // M[i, L, R]: 第 i 行访问[L, R]区间后最优代价(包含行移位代价)
        // i行下标0-based, L, R为1-based列

        // DP
        const ll INF = LLONG_MAX / 2;
        vector<vector<ll>> dp(n, vector<ll>(m + 1, INF));

        // dp[0][x] = M[0,1,x]
        {
            int i = 0;
            for (int x = 1; x <= m; x++)
            {
                ll best = INF;
                int len = x - 1 + 1; // from 1 to x
                for (int s = 0; s < m; s++)
                {
                    ll sumv = pre[i][x - 1 + s + 1] - pre[i][s];
                    ll val = k * s + sumv;
                    if (val < best)
                        best = val;
                }
                dp[0][x] = best;
            }
        }

        for (int i = 1; i < n; i++)
        {
            vector<vector<ll>> Mrow(m + 1, vector<ll>(m + 1, INF));

            for (int L = 1; L <= m; L++)
            {
                for (int R = L; R <= m; R++)
                {
                    ll best = INF;
                    int len = R - L + 1;
                    for (int s = 0; s < m; s++)
                    {
                        ll sumv = pre[i][R - 1 + s + 1] - pre[i][L - 1 + s];
                        ll val = k * s + sumv;
                        if (val < best)
                            best = val;
                    }
                    Mrow[L][R] = best;
                }
            }

            for (int x = 1; x <= m; x++)
            {
                ll ans = INF;
                for (int y = 1; y <= x; y++)
                {
                    ll candi = dp[i - 1][y] + Mrow[y][x];
                    if (candi < ans)
                        ans = candi;
                }
                dp[i][x] = ans;
            }
        }

        cout << dp[n - 1][m] << "\n";
    }

    return 0;
}