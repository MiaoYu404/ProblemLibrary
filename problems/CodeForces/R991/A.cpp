#include <bits/stdc++.h>
using namespace std;

int t, n, m;

void init() {
    cin >> n >> m;
}
int main() {
    cin >> t; while (t--) {
        init();
        int cnt = 0, tot = 0;
        bool flag = false;
        for(int i = 1; i <= n; i++) {
            string s; cin >> s;
            int len = s.length();

            if(cnt + len > m && !flag) {cout << tot << endl; flag = true;}
            else {cnt += len; tot++;}
        }
        if(!flag) cout << tot << endl;
    }
    return 0;
}