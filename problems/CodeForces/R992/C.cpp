#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;

long long getpow (int x) {
    long long tmp = 1;
    for (int i = 1; i <= x; i++) {
        tmp *= 2;
    }
    return tmp;
}
int main () {
    int t; cin >> t; while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        int a[maxn]; for (int i = 1; i <= n; i++) a[i] = i;
        queue<int> last;
        if (n < 41) {
            long long limit = getpow( n - 1 );
            if (k > limit) {cout << -1 << endl; continue;}
        }

        long long tmp = k - 1;
        int index = 1;
        while(tmp != 0) {
            if(tmp % 2) last.push(a[n - index]), a[n - index] = 0;
            tmp /= 2;
            index ++;
        }

        for (int i = 1; i <= n; i++) {
            if (a[i] != 0) cout << i << " ";
        }
        while (!last.empty()) {
            int x = last.front();
            cout << x << " ";
            last.pop();
        }
        cout << endl;
    }
}