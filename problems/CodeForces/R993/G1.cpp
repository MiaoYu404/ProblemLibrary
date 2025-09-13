#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 10;
int tt, n;
int r[maxn];
/*
struct node{
    int a[maxn];
};
*/

bool check (vector<int>& x, vector<int>& y) {
    for (int i = 0; i < n; i++) {
        if (x[i] != y[i]) return false;
    }
    return true;
}

int main () {
    cin >> tt; while (tt--) {
        cin >> n;
        vector<int> s;

        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            r[i] = x;
            s.push_back(1);
        }
        
        vector<int> pre;
        ll y = 1;
        while (check(pre, s)) {
            pre = s; y++;
            vector<int> Node(n + 1);
            for (int i = 0; i < n; i++) Node.push_back(0);
            for (int i = 0; i < n; i++) {
                if(s[i]) {
                    Node[r[i + 1] - 1] = 1;
                }
            }
            s = Node;
        }
        cout << y << endl;
    }
}