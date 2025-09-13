// Codeforces Round 1027 (Div. 3) F. Small Operations
// tags: dp, 数论
// 难度: *2000
// link: https://codeforces.com/problemset/problem/2114/F

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return (b > 0) ? gcd(b, a % b) : a;
}

int f(int u, int k) {
    vector<int> h;
    for (int i = 1; i <= u / 2; i++) {
        if (u % i == 0) h.push_back(i);
    }
    h.push_back(u);

    vector<int> dp(h.size(), 100);
    dp[0] = 0;
    for (int i = 0; i < h.size(); i++) {
        for (int j = i + 1; j <= h.size() - 1; j++) {
            if (h[j] % h[i] == 0 and h[j] / h[i] <= k) {
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }
    }
    return dp.back();
}

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int u = x / gcd(x, y);
    int v = y / gcd(x, y);

    int ans1 = f(u, k);
    int ans2 = f(v, k);
    if (ans1 > 50 or ans2 > 50) cout << -1 << endl;
    else cout << ans1 + ans2 << endl;
}

int main () {
    int tt; cin >> tt; while (tt--) {
        solve();
    }
    return 0;
}
// 有点 bug 版
/*
bool isPrime(int n) {
    int halfN = n / 2;
    for (int i = 2; i <= halfN; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

queue<int> fun(int n) {
    queue<int> divs;
    int halfN = n / 2;
    for (int div = 2; div <= halfN; div++) {
        while (n % div == 0) {
            divs.push(div);
            n /= div;
        }
    }
    return divs;
}
void solve() {
    
    queue<int> xD;
    if (x != 1) {
        if (isPrime(x)) xD.push(x);
        else xD = fun(x);
    }
    queue<int> yD;
    if (y != 1) {
        if (isPrime(y)) yD.push(y);
        else yD = fun(y);
    }

    vector<int> a, b; // a for addition, b for erase
    while (!xD.empty() and !yD.empty()) {
        int valX = xD.front(), valY = yD.front();
        if (valX == valY) {
            xD.pop(), yD.pop();
        } else if (valX > valY) {
            // add needed
            yD.pop();
            a.push_back(valY);
        } else {
            // erase needed
            xD.pop();
            b.push_back(valX);
        }
    }
    while (!xD.empty()) {
        int valX = xD.front(); xD.pop();
        b.push_back(valX);
    }
    while (!yD.empty()) {
        int valY = yD.front(); yD.pop();
        a.push_back(valY);
    }
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (!a.empty()) if (a.front() > k) {
        cout << -1 << endl; return;
    }
    if (!b.empty()) if (b.front() > k) {
        cout << -1 << endl; return;
    }

    // start counting steps;
    int step = 0;
    while (!a.empty()) {
        int tmp = 1;
        for (auto it = a.begin(); it != a.end(); ) {
            int val = *it;
            if (tmp * val <= k) {
                tmp *= val; it = a.erase(it);
            } else {
                it++;
            }
            if (a.empty()) break;
        }
        if (tmp > 1) step++;
    }
    while (!b.empty()) {
        int tmp = 1;
        for (auto it = b.begin(); it != b.end();) {
            int val = *it;
            if (tmp * val <= k) {
                tmp *= val; it = b.erase(it);
            } else {
                it++;
            }
            if (b.empty()) break;
        }
        if (tmp > 1) step++;
    }
    cout << step << endl;
}*/