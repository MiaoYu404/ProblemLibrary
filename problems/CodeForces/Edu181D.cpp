// Codeforces Edu R181 D
// tag: probability
// diff: *1600
// link: 

#include <bits/stdc++.h>
using ll = long long;

struct seg{
    ll l, r;
    ll p, q;
    seg() {};
    seg(ll _l, ll _r, ll _p, ll _q) : l(_l), r(_r), p(_p), q(_q) {};
    bool operator<(seg o) const { return r == o.r ? l < o.l : r < o.r; }
};

// 快速幂
ll pow(ll a, ll b, ll p)
{
    ll res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p)
    {
        if (b % 2)
        {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

// 快速幂求逆元
ll inverse(ll a, ll p) { return pow(a, p - 2, p); }

const int N = 2e5 + 10;
const ll MOD = 998244353;
int n, m;
ll f[N][3];
std::vector<seg> segs[N];

void init() {
    f[0][0] = 1; f[0][1] = 1; f[0][2] = 1;
    for (int i = 1; i <= m; i++) {
        f[i][0] = 0;
        f[i][1] = 0;
        f[i][2] = 1;
        segs[i].clear();
    }
}

ll modMul (ll a, ll b) { return ((a * b) % MOD + MOD) % MOD; }
ll modDiv (ll a, ll b) { return ((a * inverse(b, MOD)) % MOD + MOD) % MOD; }

void solve() {
    std::cin >> n >> m;
    init();
    for (int i = 1; i <= n; i++) {
        ll l, r, p, q;
        std::cin >> l >> r >> p >> q;
        seg s = seg(l, r, p, q);
        segs[r].push_back(s);
        f[l][2] = modMul(f[l][2], q - p);
        f[l][2] = modDiv(f[l][2], q);
    }
    
    for (int i = 1; i <= m; i++) {
        f[i][2] = modMul(f[i][2], f[i - 1][2]);
        std::set<int> vis;
        for (seg s : segs[i]) {
            ll l = s.l, r = s.r, p = s.p, q = s.q;
            ll ans;
            ans = modDiv(p, q);                 // p/q
            ans = modMul(ans, f[l - 1][1]);     // p/q * l (with not exist added)
            ll div;
            div = modDiv(q - p, q);             // (q-p) / q
            ans = modDiv(ans, div);             // add another not exist

            f[r][1] = ((f[r][1] + ans) % MOD + MOD) % MOD;  // answer array
        }

        f[i][0] = modMul(f[i][1], f[i][2]);
    }

    std::cout << f[m][0] << std::endl;
}

int main () {
    solve();
}