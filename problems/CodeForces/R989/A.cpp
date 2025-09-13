#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm (int a, int b) {
    return a * b / gcd(a, b);
}
int main() {
    //m = ap + r = bq + r;
    // m - r % a , % b == 0
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        cout << lcm(a, b) << endl;
    }
    return 0;
}