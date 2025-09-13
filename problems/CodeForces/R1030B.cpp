// Codeforces Round 1030 (Div. 2) B. Make It Permutation
// tags: 构造
// 难度:
// link: https://codeforces.com/contest/2118/problem/B

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using ll = long long;

const int MOD = 20000101;

void solve () {
    int n; cin >> n;
    cout << n - 1 + n - 2 << endl;
    for (int i = 2; i <= n; i++) {
        cout << i << " " << 1 << " " << i << endl;
    }

    int num = 2;
    for (int i = n - 2; i >= 1; i--, num++) {
        cout << i << " " << n - num + 1 << " " << n << endl;
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt; cin >> tt; while (tt--) {solve();}

    return 0;
}

// 记得开 long long