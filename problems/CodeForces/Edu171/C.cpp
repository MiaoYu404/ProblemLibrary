#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;
deque<int> q;

int main () {
    cin >> t; while (t--) {
        cin >> n >> s;
        int len = s.length();
        long long ans = 0;
        for (int i = len - 1; i >= 0; i--) {
            int x; x = s[i] - '0';
            if (x == 1) q.push_back(i + 1);
            else {
                if (!q.empty()) q.pop_front();
                ans += i + 1;
            }
        }

        while (!q.empty()) {
            ans += q.back();
            q.pop_back();
            if (q.empty()) break;
            q.pop_front();
        }

        cout << ans << '\n';
    }
}