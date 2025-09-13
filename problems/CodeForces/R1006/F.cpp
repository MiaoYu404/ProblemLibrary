#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt; cin >> tt; while (tt--) {
        int n, k;
        cin >> n >> k;

        for (int j = 1; j <= n; j++) {
            if (((j - 1) & (n - 1)) == (j - 1)) {
                cout << k;
            } else {
                cout << 0;
            }
            if (j < n) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}