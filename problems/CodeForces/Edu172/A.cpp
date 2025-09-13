#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 55;
int num[maxn];

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            num[i] = x;
        }

        sort(num + 1, num + 1 + n, greater<int>() );

        int index = 1; int cnt = 0;
        for (; index <= n; index ++) {
            cnt += num[index];
            if(cnt + num[index + 1] > k) break;
        }
        cout << k - cnt << endl;
    }
    return 0;
}