#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

typedef long long ll;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt; cin >> tt; while (tt--) {
        int a, b; cin >> a >> b;
        if (b - a == 1 or ( a > b and (a - b + 1) % 9 == 0) ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}