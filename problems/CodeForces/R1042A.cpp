#include <bits/stdc++.h>
using namespace std;

#define FOR(i, x, y) for (int i = x; i <= y; i++)
#define mp make_pair
#define fi first
#define se second

typedef unsigned long long ull;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        int x; cin >> x; a[i - 1] -= x;
    }
    int cnt = 0;
    for (int x : a) {
        cnt += max(0, x);
    }
    cout << cnt + 1 << endl;
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