#include <bits/stdc++.h>
using namespace std;

int solve (vector<int> &a, int k) {
    if (a.size() == 1) return a[0];

    int cmp = a.back();
    a.pop_back();

    vector<int> v1, v2;
    while (!a.empty()) {
        int x = a.back(); a.pop_back();
        if (x < cmp) v1.push_back(x);
        else v2.push_back(x);
    }

    if (v1.size() == k) return cmp;
    else if (v1.size() > k) return solve(v1, k);
    else return solve(v2, k - v1.size() - 1);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> a;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x; a.push_back(x);
    }
    
    cout << solve(a, k);
}