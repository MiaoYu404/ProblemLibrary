#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll n, k;
        cin >> n >> k;
        ll e = k - 1; // Largest even <= k
        ll ans;
        if (n % 2 == 0) {
            ans = (n + e - 1) / e; // ceil(n / e)
        } else {
            ans = 1 + ((n - k) + e - 1) / e; // 1 + ceil((n - k) / e)
        }
        cout << ans << endl;
    }
    return 0;
}