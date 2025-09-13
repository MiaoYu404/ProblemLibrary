#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

typedef long long ll;

const int N = 2e5 + 10;
int n;
struct node {
    int a, b;
}nodes[N];

bool cmp (const node x, const node y) {
    if (min(x.a, x.b) <= n or min(y.a, y.b) <= n)
        return min(x.a, x.b) < min(y.a, y.b);
    else 
        return max(x.a, x.b) < max(y.a, y.b);
}

// dp[node][inverse?][odd?] = true / false;
// [T / F] for a < a and b < b
// [odd / even] for when node - 1 is [even / odd] since inverse is true
// [odd / even] for when node - 1 is [odd / even] since inverse is false;
int dp[N][2][2];

void solve () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nodes[i].a;
    }
    for (int i = 1; i <= n; i++) {
        cin >> nodes[i].b;
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0][0] = false;
        dp[i][0][1] = false;
        dp[i][1][0] = false;
        dp[i][1][1] = false;
    }
    sort(nodes + 1, nodes + n + 1, cmp);
    if (nodes[1].a > n + 1 or nodes[1].b > n + 1) {cout << "NO\n"; return;}
    dp[1][0][0] = 1; dp[1][1][1] = 1;
    // ans is dp[n][0][0] and dp[n][1][0]; if any one can be 1, it is possible;
    for (int i = 2; i <= n; i++) {
        dp[i][0][0] = 0;
        dp[i][0][1] = 0;
        dp[i][1][0] = 0;
        dp[i][1][1] = 0;
        if (nodes[i].a > nodes[i - 1].a and nodes[i].b > nodes[i - 1].b) {
            // not inverse
            dp[i][0][0] = dp[i - 1][0][0];
            dp[i][0][1] = dp[i - 1][0][1];
            dp[i][1][0] = dp[i - 1][1][1];
            dp[i][1][1] = dp[i - 1][1][0];
        }
        if (nodes[i].a > nodes[i - 1].b and nodes[i].b > nodes[i - 1].a) {
            // inverse
            dp[i][0][0] = max(dp[i][0][0], dp[i - 1][1][0]);
            dp[i][0][1] = max(dp[i][0][1], dp[i - 1][1][1]);
            dp[i][1][0] = max(dp[i][1][0], dp[i - 1][0][1]);
            dp[i][1][1] = max(dp[i][1][1], dp[i - 1][0][0]);
        }
    }
    if (dp[n][0][0] or dp[n][1][0]) cout << "YES\n";
    else cout << "NO\n";
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt; while (tt--) {
        solve();
    }

    return 0;
}