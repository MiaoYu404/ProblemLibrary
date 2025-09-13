// Codeforces Round 1030 (Div. 2) C. Make It Beautiful
// tags: 贪心、位运算
// 难度: 
// link: https://codeforces.com/contest/2118/problem/C

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using ull = unsigned long long;
using ll = long long;

const int MOD = 20000101;

int cntBits[65];
void decompose (int x) {
    int index = 0;
    while (x) {
        cntBits[index] += x % 2;
        x >>= 1; index++;
    }
    return ;
}

void solve()
{
    ull n, k; cin >> n >> k;
    memset(cntBits, 0, sizeof(cntBits));
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        decompose(x);
    }

    for (int i = 0; i <= 65 and k > 0; i++) {
        ull left = n - cntBits[i];
        ull can = k / (1ll << i);
        cntBits[i] += min(left, can);
        if (can < left) break;
        k -= left * (1ll << i);
    }

    int ans = 0;
    for (int i = 0; i <= 60; i++) {
        ans += cntBits[i];
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

    return 0;
}

// 记得开 long long