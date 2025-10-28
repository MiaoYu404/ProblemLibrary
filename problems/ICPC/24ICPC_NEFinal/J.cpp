#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
ll preEp[N];
ll preF[N];
ll F[N];

int bSearchEP(ll l, ll r, ll x) {
    ll ret = -1;
    ll mid;
    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (preEp[mid] < x) l = mid + 1;
        else if (preEp[mid] > x) r = mid - 1;
        else {
            ret = mid; break;
        }
    }
    if (ret == -1) ret = r;
    return ret;
}

bool cmp (pair<ll, ll> &a, pair<ll, ll> &b) {
    return a.second < b.second;
}

int main () {
    int tt; cin >> tt; while (tt--) {
        int n, m, q; cin >> n >> m >> q;
        
        vector < pair<ll, ll> > tk(n + 1);
        for (int i = 1; i <= n; i++) {
            ll a; cin >> a;
            tk[i].first = a;
        }
        for (int i = 1; i <= n; i++) {
            ll d; cin >> d;
            tk[i].second = d;
        }

        sort(tk.begin(), tk.end(), cmp);

        preEp[0] = 0;
        for (int i = 1; i <= m; i++) {
            ll t; cin >> t;
            preEp[i] = preEp[i - 1] + t;
        }

        memset(F, 0x3F, sizeof(F));
        F[0] = 0; tk[0].first = 0, tk[0].second = 0;
        for (int i = 1; i <= n; i++) {
            // F[1] = tk[1].second - tk[1].first
            // F[2] = (tk[2].second -tk[1].second) - tk[2].first
            F[i] = (tk[i].second - tk[i - 1].second) - tk[i].first;
        }
        ll tmp = 0;
        for (int i = n; i >= 1; i--) {
            if (F[i] < 0) {
                tmp += F[i];
                F[i] = 0;
                continue;
            }
            ll change = max(F[i] * (-1LL), tmp);
            F[i] += change;
            tmp -= change;
        }

        memset(preF, 0x3F, sizeof(preF));
        preF[0] = 0;
        for (int i = 1; i <= n; i++) {
            preF[i] = preF[i - 1] + F[i];
        }

        for (int i = 1; i <= q; i++) {
            ll t; cin >> t;
            // 二分ddl
            ll l = 1, r = n, ret = -1;
            ll mid;
            while (l <= r) {
                mid = l + ((r - l) >> 1);
                if (tk[mid].second < t) l = mid + 1;
                else if (tk[mid].second > t) r = mid - 1;
                else {
                    ret = mid; break;
                }
            }
            if (ret == -1) ret = l;

            // 二分可用时间
            ll x = preF[ret];
            // 区间为 if (F[ret] + tk[ret - 1].second > t) x = t - tk[ret - 1].second;
            if (F[ret] + tk[ret - 1].second > t) x = t - tk[ret - 1].second + preF[ret - 1];

            cout << bSearchEP(0, m, x) << ' ';
        }
        cout << '\n';
    }
    return 0;
}