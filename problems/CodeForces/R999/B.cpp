#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        unordered_map<int, int> mp;
        priority_queue<int, vector<int>, greater<int> > pq;
        priority_queue<int> num;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            mp[x]++;
            if (mp[x] == 2) pq.push(x);
            else num.push(x);
        }
        if (pq.empty()) {cout << -1 << endl; continue;}
        int a = num.top(); num.pop();
        int b = num.top(); num.pop();
        if (b - a < 2 * pq.top()) cout << a << " " << b << " " << pq.top() << " " << pq.top() << endl;
        else cout << -1 << endl;
    }
    return 0;
}