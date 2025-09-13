#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
int c[maxn];
int n;

void init() {
    cin >> n;
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++) {
        int x; cin >> x; c[x]++;
    }
}

int main() {
    int t; cin >> t;
    while(t--) {
        init();

        int ans = 0, tot = n, ones = 0;
        for (int i = 1; i <= n; i++) {
            if (c[i] == 0) {tot--; continue;}
            else if (c[i] > 1) ans++;
            else ones++;
        }
        
        cout << 2 * (ones / 2 + ones % 2) + tot - ones << endl;
    }
    return 0;
}