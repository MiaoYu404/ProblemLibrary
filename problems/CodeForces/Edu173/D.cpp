#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

int main () {
    int tt; cin >> tt; while (tt--) {
        ll l, r, G; cin >> l >> r >> G;
        ll lb = l / G + (l % G ? 1 : 0);
        ll rb = r / G;
        ll A = -1, B = -1;
        for (ll i = lb; i <= min(rb, lb + 16); i++) {
            for (ll j = rb; j >= max(rb - 6, lb); j--) {
                if (gcd(i, j) == 1 and j - i > B - A or (j == 1 and i == 1)) {
                    A = i; B = j; break;
                }
            }
        }
        if (A != -1 or B != -1) A *= G, B *= G;
        cout << A << " " << B << endl;
    }
}