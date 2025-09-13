#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt; while (tt--) {
        int n, m; cin >> n >> m;
        vector<ll> a, b;
        for (int i = 1; i <= n; i++) {
            ll x; cin >> x;
            a.push_back(x);
        }
        for (int i = 1; i <= m; i++) {
            ll x; cin >> x;
            b.push_back(x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int minLen = min(a.size(), b.size()), maxLen = max(a.size(), b.size());
        int kmax = min(minLen, maxLen / 2)
                 + max(0, min(minLen - maxLen / 2, maxLen / 2) ) / 2;
        vector<ll> pA, pB;

        pA.push_back(0);
        pB.push_back(0);
        for (int i = 0, j = n - 1; i <= n / 2, j >= n / 2; i++, j--) {
            ll val = a[j] - a[i];
            pA.push_back(val);
        }
        for (int i = 0, j = m - 1; i <= m / 2; i++, j--) {
            ll val = b[j] - b[i];
            pB.push_back(val);
        }

        cout << kmax << endl;
        int i = 1, j = 1;
        ll ans = 0;
        for (int k = 1; k <= kmax; k++) {
            if (n - (j - 1) - (i - 1) * 2 < 2) {
                // A done
                if (n - (j - 1) - (i - 1) * 2 == 1) {
                    ans += pB[j]; j++;
                } else {
                    ans -= pA[i - 1]; i--;
                    ans += pB[j]; j++;
                    if (i != 0) {ans += pB[j]; j++;}
                }

            } else if (m - (i - 1) - (j - 1) * 2 < 2) {
                // B done
                if (m - (i - 1) - (j - 1) * 2 == 1) {
                    ans += pA[i]; i++;
                } else {
                    ans -= pB[j - 1]; j--;
                    ans += pA[i]; i++;
                    if (j != 0) {ans += pA[i]; i++;}
                }
                
            } else {
                if (pA[i] > pB[j]) {
                    ans += pA[i]; i++;
                } else {
                    ans += pB[j]; j++;
                }

            }

            cout << ans << " ";
        }
        cout << endl;
    }
}