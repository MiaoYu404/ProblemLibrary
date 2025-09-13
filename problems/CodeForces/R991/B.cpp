#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t, n; 
ll a, b;

void init() {
    cin >> n;
    a = 0, b = 0;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if(i % 2 == 1) a += x;
        else b += x;
    }
}

int main() {
    cin >> t; while(t--) {
        init();
        if(a % (n / 2 + n % 2) != 0){
            cout << "NO" << endl; continue;
        }
        if(b % (n / 2) != 0){
            cout << "NO" << endl; continue;
        }
        if(a / (n / 2 + n % 2) == b / (n / 2)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}