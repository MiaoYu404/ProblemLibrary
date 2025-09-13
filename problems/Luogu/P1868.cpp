#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 3e6 + 10;

int N, x, y, mx = 0;
vector<int> beg[MAXN];
int dp[MAXN];

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> x >> y;
        beg[y].push_back(x - 1);
        mx = max(mx, y);
    }
    
    //状态转移，dp[i] = dp[b] + i - b;
    //为什么不重合？ 因为dp[b]就是以b结尾，确保了之后不可能存在被覆盖的问题。
    
    for(int i = 1; i <= mx; i++)
    {
        dp[i] = dp[i - 1];
        for(int j = 0; j < beg[i].size(); j++)
        {
            int b = beg[i][j];
            dp[i] = max(dp[i], dp[b] + i - b);
        }
    }
    cout << dp[mx];

    return 0;
}