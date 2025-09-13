#include <bits/stdc++.h>
using namespace std;

int a[20];
int n;
int main() {
    a[0] = 0, a[1] = 1;
    for (int i = 2; i <= 18; i++) a[i] = 2 * a[i - 1] + 2;

    int t; cin >> t; while (t--) {
        int n; cin >> n;
        for (int i = 1; i <= 18; i++) {
            if (n <= a[i] && a[i - 1] < n){
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}