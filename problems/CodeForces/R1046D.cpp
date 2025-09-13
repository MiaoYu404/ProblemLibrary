// Codeforces R1046 D. For the champion
// tag: math
// diff:
// link: https://codeforces.com/contest/2136/problem/D

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
void solve()
{
    cin >> n;
    ll xpy = LONG_MIN, xmy = LONG_MIN;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        xpy = max(xpy, x + y);
        xmy = max(xmy, x - y);
    }

    ll s;
    for (int i = 1; i <= 2; i++)
    {
        cout << "? R " << 1000000000 << endl;
        cout << "? U " << 1000000000 << endl;
    }
    cout.flush();
    cin >> s >> s >> s >> s;

    ll s1 = s;

    for (int i = 1; i <= 4; i++)
    {
        cout << "? D " << 1000000000 << endl;
    }
    cout.flush();
    cin >> s >> s >> s >> s;

    ll s2 = s;

    ll ansX = ((xpy + xmy + s1 + s2) >> 1) - 4000000000LL;
    ll ansY = (xpy - xmy + s1 - s2) >> 1;

    cout << "! " << ansX << " " << ansY << endl;
    cout.flush();
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
}