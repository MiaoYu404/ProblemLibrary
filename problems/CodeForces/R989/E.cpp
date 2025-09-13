#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e10;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (k == n) {
            cout << "Yes" << endl;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if((i + j) % n == 0) {cout << n << " "; continue;}
                    cout << (i + j) % n << " ";
                }
                 cout << endl;
            }
            continue;
        }

        if(k % 2 == 1) {cout << "NO" << endl; continue;}
        for (int i = 1; i <= k / 2; i++) {
            int a[maxn];
            
        }
    }
}