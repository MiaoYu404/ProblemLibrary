// AcWing 89. a^b
// tag: bitwise
// 难度: 简单
// link: https://www.acwing.com/problem/content/91/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll a, b, p; cin >> a >> b >> p;

    if (b == 0) {cout << 1 % p << endl; return 0;}
    
    ll tmp = a % p;
    ll ans = 1;
    while (b != 0) {
        if (b % 2) {
            ans *= tmp; ans %= p;
        }
        tmp *= tmp; tmp %= p; b /= 2;
    }
    cout << ans << endl;
    return 0;
}