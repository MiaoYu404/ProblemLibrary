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
    for (int i = 1; i <= n - 2; i++) {
        if (i % 2) printf("-1 ");
        else printf("%d ", 3);
    }
    if ((n - 1) % 2) { printf("-1 2\n");}
    else printf("3 -1\n");
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