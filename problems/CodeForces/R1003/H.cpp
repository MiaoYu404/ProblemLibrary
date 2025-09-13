#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

typedef long long ll;
using ll = long long;
const int N = 2e5 + 10;

ll ans = 0;
struct node{
    int l, r;
    int sum1, sum0;
}t[4 * N + 2];

int a[N + 2];

// 更新父节点
void pushup(int u) {
    t[u].sum1 = t[u * 2].sum1 + t[u * 2 + 1].sum1;
    t[u].sum0 = t[u * 2].sum0 + t[u * 2 + 1].sum0;
}

void build (int u, int l, int r) {
    t[u].l = l;
    t[u].r = r;
    if (l == r) {
        t[u].sum1 = 0;
        t[u].sum0 = 0;
        if (a[l] == 1) t[u].sum1++;
        else t[u].sum0++;
        return;
    }

    int mid = l + ((r - l) >> 1);
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
    
    // 区间求和
    pushup(u);
}

// 单点修改
void modify (int u, int x) {
    if (t[u].l == t[u].r) {
        if (a[ t[u].l ] == 1) {
            ans = (ans - (ll)(pow(2, t[u].sum1))) % MOD;
            ans = (ans + (ll)(pow(2, t[u].sum0))) % MOD;
            t[u].sum1--;
            t[u].sum0++;
            a[ t[u].l ] = 0;
        }
        else {
            ans = (ans - (ll)(pow(2, t[u].sum0))) % MOD;
            ans = (ans + (ll)(pow(2, t[u].sum1))) % MOD;
            t[u].sum1++;
            t[u].sum0--;
            a[ t[u].l ] = 1;
        }
        return ;
    }
    int mid = (t[u].l + t[u].r) >> 1;
    if (x <= mid) modify(u * 2, x);
    else modify(u * 2 + 1, x);

    pushup(u);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt; cin >> tt; while (tt--) {
        string s; cin >> s; int n = s.length();
        for (int i = 1; i <= n; i++) {
            a[i] = s[i - 1] - '0';
        }
        build(1, 1, n);
        ans = pow(2, n) - 1;
        ll sum[2] = {0, 0};
        for (int i = 1; i <= n; i++) {
            (ans += sum[(a[i] + 1) % 2] * (ll)pow(2, n - i)) %= MOD;
            (sum[a[i]] += (ll)pow(2, i - 1)) %= MOD;
        }
        int q; cin >> q;
        while (q--) {
            int x; cin >> x;
            modify(1, x);
            cout << ans << endl;
        }
    }

    return 0;
}