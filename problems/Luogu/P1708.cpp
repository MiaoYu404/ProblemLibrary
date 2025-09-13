#include <iostream>

using namespace std;
using ll = long long;

const int maxn = 105;
int dp[8][maxn][2];

void init() {
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    for (int i = 1; i <= 7; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int m = 0; m <= 1; m++) {
                if (m == 0){
                    dp[i][j][m] = dp[i - 1][j - 1][0];
                    for (int l = 0; l <= 9; l++) {
                        if (j - l < 0) break;
                        dp[i][j][m] += dp[i - 1][j - l][1];
                    }
                }
                else
                    for (int l = 0; l <= 9; l++) {
                        if (j - l < 0) break;
                        dp[i][j][m] += dp[i - 1][j - l][1];
                    }
            }
        }
    }
}

int main () {
    init();
    int tt; cin >> tt; while (tt--) {
        int n, k; cin >> n >> k;

        ll ans = 0;
        for (int i = 1; i <= k; i++) {
            ans += dp[n][i][1];
        }
        cout << ans << endl;
    }
    return 0;
}