// 2107A - LRC and VIP
// tag: 贪心, 数论
// 难度: *800
// link: https://codeforces.com/problemset/problem/2107/A

#include <bits/stdc++.h>
using namespace std;
using namespace std;

int main () {
    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            nums.push_back(x);
        }

        if (*min_element(nums.begin(), nums.end()) == *max_element(nums.begin(), nums.end())) {
            cout << "No" << endl;
            continue;
        } else {
            cout << "Yes" << endl;
            vector<int>::iterator maxn = max_element(nums.begin(), nums.end());
            for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
                if (it == maxn) cout << 2 << " ";
                else cout << 1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}