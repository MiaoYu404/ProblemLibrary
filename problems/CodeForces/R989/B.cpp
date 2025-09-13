#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
char s[maxn];

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m, k; cin >> n >> m >> k;
        cin >> s;
        int cnt = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            char x = s[i];
            if(x == '0') cnt++;
            else{
                cnt = 0; continue;
            }
            if(cnt == m) {
                for (int j = i; j < i + k; j++) if(j < n) s[j] = 1;
                cnt = 0; ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}