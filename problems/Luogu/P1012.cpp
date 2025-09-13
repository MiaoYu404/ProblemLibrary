#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp (const string &a, const string &b) {
    return a + b > b + a;
}
int main () {
    int n; cin >> n;
    vector <string> num;

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        num.push_back(to_string(x));
    }
    sort(num.begin(), num.end(), cmp);
    for (auto x : num) cout << x;
}