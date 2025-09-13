#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int num[N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        memset(num, 0, sizeof(num));
        int k2 = 0;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            // 三种卡，2 在自己手里，1 在自己手里，还有 0；
            // 尽量用 2，其次，对方每打出一个就跟，剩下的都是对面的分
            // 所以就是 “2” - 对面“2” 得到谁先出 1
            // 出 1 之后一定会跟，理论上先手会获得
            num[x] += 1; if (num[x] == 2) k2 += 1;
        }
        cout << k2 << endl;
    }
}