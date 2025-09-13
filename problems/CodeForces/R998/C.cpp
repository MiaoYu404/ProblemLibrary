#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int cnt[N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt; while (tt--) {
        int n, k; cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            cnt[x] ++;
        }
        vector<int> num;
        for (int i = 1; i <= k - 1; i++) {
            num.push_back(min(cnt[i], cnt[k - i]);
        }
        int impo = 0;
        for (int i = k; i <= n; i++) {
            impo += cnt[i];
        }
        int extra = impo % 2;
        
        int ans = 0;
        for (int i = 1; i <= n / 2; i++) {
            ans += min(cnt[i], cnt[k - i]);
        }
        cout << ans << endl;
    }
    return 0;
}