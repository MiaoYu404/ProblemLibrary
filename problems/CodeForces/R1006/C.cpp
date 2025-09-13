#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

const int MOD = 1e9 + 7;

int check_kth_bit (int x, int k) {
    return (x >> k) & 1;
}

// 有多少个 1
int count_on_bits (int x) {
    int ans = 0;
    for (int k = 0; k < 32; k++) {
        if (check_kth_bit(x, k)) ans++;
    }
    return ans;
}

bool check_power_of_2 (int x) {
    return count_on_bits(x) == 1;
}

void solve() {
    int n, x; cin >> n >> x;
    cout << x << " ";
    int k = 0;
    bool flag = false;
    for (int i = 0; i < n - 1; i++) {
        if (i == 0) {cout << 0 << " "; continue;}
        if (check_power_of_2(i)) {
            if (!check_kth_bit(x, k)) flag = true;
        }
        if (flag) cout << 0 << " ";
        else cout << i << " ";
    }
    cout << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt; cin >> tt; while (tt--) {
        solve();
    }

    return 0;
}