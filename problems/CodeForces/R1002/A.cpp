#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

typedef long long ll;

const int N = 55;
ll a[N], b[N];

int main () {
    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            ll x; cin >> x;
            a[i] = x;
        }
        for (int i = 1; i <= n; i++) {
            ll x; cin >> x;
            b[i] = x;
        }
        set<int> s1, s2;
        for (int i = 1; i <= n; i++) {
            if (s1.find(a[i]) == s1.end()) s1.insert(a[i]);
            if (s2.find(b[i]) == s2.end()) s2.insert(b[i]);
        }

        if (s1.size() + s2.size() >= 4) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}