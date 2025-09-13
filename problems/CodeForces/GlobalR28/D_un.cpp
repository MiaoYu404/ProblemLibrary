#include <bits\stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e5 + 10;
int a[N], b[N], c[N], ans[N];
int K;

int main () {
    int tt; cin >> tt; while (tt--) {
        memset(c, 0, sizeof(c));
        memset(ans, 0, sizeof(ans));
        int n, m; cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x; a[i] = x;
        }
        K = a[1];
        for (int i = 1; i <= m; i++) {
            int x; cin >> x; b[i] = x;
        }

        int index = 1;
        sort(a + 1, a + n + 1, greater<int>() );
        sort(b + 1, b + m + 1, greater<int>() );
        for (int i = 1; i <= m; i++) {
            if (b[i] < K) break;
            while (a[index] > b[i]) ++index;
            ++c[index - 1];
        }

        for (int k = 1; k <= m; k++) {
            ans[k] += m / k;
            for (int j = 0; j <= n; j++) {
                if (a[j] == K) break;
                ans[k] += min(m / k, c[j]);
            }
            cout << ans[k] << " ";
        }
    }
}