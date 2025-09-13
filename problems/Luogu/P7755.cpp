#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

typedef long long ll;

const int N = 2e3 + 510;
string a[N], b[N];
set<string> vis;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        a[i] = s;
    }
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        b[i] = s;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = 1; while (j <= n and a[i] != b[j]) {
            //if (vis[j]) ans++;
            j++;
        }
        j++;
        while (j <= n) {
            if (vis.find(b[j]) == vis.end()) ans++;
            j++;
        }
        vis.insert(a[i]);
    }
    cout << ans << '/' << (n - 1) * n / 2 << '\n';
}