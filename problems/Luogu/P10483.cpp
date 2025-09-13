#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 20;
int weight[N];
int cap[N];
int n, w;
int ans = 20;

void dfs(int now, int cnt) {
    if (cnt >= ans) return ;
    if (now == n + 1) {ans = min(ans, cnt); return ;}

    for (int i = 1; i <= cnt; i++) {
        if (w - cap[i] >= weight[now]) {
            cap[i] += weight[now];
            dfs(now + 1, cnt);
            cap[i] -= weight[now];
        }
    }
    cap[cnt + 1] += weight[now];
    dfs(now + 1, cnt + 1);
    cap[cnt + 1] -= weight[now];
}

int main () {
    cin >> n >> w;
    memset(cap, 0, sizeof(cap));
    for (int i = 1; i <= n; i++) {
        int x; cin >> x; weight[i] = x;
    }
    sort(weight + 1, weight + 1 + n, greater<int>() );
    //cap[1] = weight[1];
    dfs(1, 1);
    cout << ans;
}