#include <bits/stdc++.h>
using namespace std;

using ll = __int128;
constexpr int N = 1e6 + 10;
ll rb[70];

ll n, k;
ll powx[70][N];

struct q {
    ll num, k;
    int ans;
};
vector<q> qs;

ll powll(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
    // return powx[b][a];
}

ll root(ll x, ll y)
{
    ll l = 1,r = rb[y];
    while(l < r)
    {
        ll mid = (l + r + 1)>>1;
        if(powll(mid, y) > x) r = mid - 1;
        else l = mid;
    }
    return l;
}

void print(__int128 x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

void solve() {
    long long n1,k1;
    scanf("%lld %lld",&n1,&k1);
    n = n1, k = k1;
    for (auto q : qs) {
        if (q.num == n && q.k == k) {
            cout << q.ans << endl;
            return ;
        }
    }

        if (k > 3)
        {
            int cnt = 0;
            ll b = 1;
            // ll a = 114429;
            while (powll(b + 1, k) - powll(b, k) <= n)
            {
                ll ak = powll(b, k) + n;
                if (ak < 0)
                {
                    b++;
                    continue;
                }
                if (powll(root(ak, k), k) == ak)
                {
                    cnt++;
                }

                b++;
            }
            qs.push_back({n, k, cnt});
            cout << cnt << endl;
            return;
        }
        else
        {
            // k == 3;
            ll rsl = 0;
            int cnt = 0;
            for (ll x = 1; x <= 4e6; x++)
            {
                if (n % x != 0)
                    continue;
                rsl = 12 * n / x - 3 * x * x;
                if (rsl < 0)
                    break;
                ll rt = root(rsl, 2);
                if (rt * rt != rsl)
                    continue;

                rsl = rt - 3 * x;
                if (rsl <= 0)
                    break;
                if (rsl % 6 != 0)
                    continue;
                cnt++;
                // return ;
            }
            qs.push_back({n, k, cnt});
            cout << cnt << endl;
            return;
        }
}

int main () {
    rb[2] = 1e18;
    rb[3] = 1e9;

    for(double i = 4; i <= 64; i++)
        rb[(int)i] = pow(1e36, 1.0 / i) + 1;

    int tt; cin >> tt; while (tt--) {
        solve();
    }
}

/*
3
7 3
15 4
31 5

2
19 3
9999 4
*/