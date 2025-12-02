#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        int num = 0;
        queue <int> ans;

        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            if (x > num) {
                num = x;
                while (!ans.empty()) ans.pop();
                ans.push(i);
            }
            else if (x == num) ans.push(i);
        }
        while (!ans.empty()) {
            int tmp = ans.front(); ans.pop();
            cout << tmp << ' ';
        }
        cout << '\n';
    }
}