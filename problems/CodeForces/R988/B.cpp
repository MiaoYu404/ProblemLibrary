#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
bool a[N];

int main() {
    int t; cin >> t;
    while(t--) {
        memset(a, false, sizeof(a));
        int n, m;
        int k; cin >> k;
        for (int i = 1; i <= k; i++) {
            int tmp; cin >> tmp;
            a[tmp] = true;
        }
        for (int i = 1; i <= k - 2; i++) {
            if((k - 2) % i != 0) continue;
            if(a[(k - 2) / i] && a[i]) {
                cout << i << " " << (k - 2) / i << endl; break;
            }
        }
    }
    return 0;
}