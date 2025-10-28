// 2024 ICPC Kunming G GCD
// tag: 暴力
// link: https://qoj.ac/contest/1871/problem/9868

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct node{ 
    ll a, b;
    int dep;
    node(ll a_, ll b_, int dep_) : a(a_), b(b_), dep(dep_) {};
};

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve () {
    ll a, b; cin >> a >> b;
    
    queue<node> q;
    q.push(node(a, b, 0));
    while (true) {
        node cur = q.front(); q.pop();

        a = cur.a; b = cur.b;
        if (a == 0 or b == 0) {
            cout << cur.dep + 1 << endl;
            break;
        }

        ll minus = a > b ? gcd(a, b) : gcd(b, a);

        q.push(node(a - minus, b, cur.dep + 1));
        q.push(node(a, b - minus, cur.dep + 1));
    }
}

int main () {
    cin.tie(0);

    int tt; cin >> tt; while (tt--) {
        solve();
    }
}