#include <iostream>

using namespace std;

const int MAXN = 1e3 + 10;
int dp[MAXN][105];
int val[105], ti[105];

int main(){
    int T, M, res = -1; cin >> T >> M;
    for(int i = 1; i <= M; i++){
        int x, t; cin >> t >> x;
        val[i] = x; ti[i] = t;
    }

    //dp[i][j] = max ( dp[i - 1][j - ti[i]] + val, dp[i - 1][j])
    dp[0][0] = 0;
    for(int i = 1; i <= M; i++) {
        for(int j = T; j >= 0; j--) {
            if(j >= ti[i]) dp[i][j] = max(dp[i - 1][j - ti[i]] + val[i], dp[i - 1][j]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[M][T];
}