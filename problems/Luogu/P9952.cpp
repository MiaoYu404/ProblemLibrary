#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> pt;
int n;
string s;

bool check(int x) {
    int dis = 0;
    int tot = 2;
    if (2 * x <= pt[0]) {
        return true;
    }
    if (x <= pt[0]) {
        tot--;
    }
    for (int i = 0; i < pt.size() - 1; i++) {
        if (pt[i] + 2 * x <= pt[i + 1]) {
            tot--;
            if (pt[i] + 3 * x <= pt[i + 1]) {
                tot--;
            }
        }
        if (tot <= 0) return true;
    }
    if (pt[pt.size() - 1] + x <= n - 1) {
        tot--; 
    }
    if (pt[pt.size() - 1] + 2 * x <= n - 1) {
        tot--;
    }
    if (tot <= 0) return true;
    return false;
}

int main () {
    cin >> n;
    cin >> s;
    // pt.push_back(0);
    for (int i = 0; i < n; i++) {
        if (s[i] - '0') {
            pt.push_back(i);
        }
    }
    int minn = N, cnt = 0;
    int i = 0;
    while (s[i] - '0' == 0) i++;
    for ( ; i < n; i++) {
        if (s[i] - '0' and cnt != 0) {
            // 1
            minn = min(minn, cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }
    // pt.push_back(s.length() - 1);

    if (pt.empty()) {
        cout << n - 1 << endl; return 0;
    }
    int l = 1, r = min(minn, n - 1);
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
}