#include <bits/stdc++.h>
using namespace std;

priority_queue< pair<int, string> > q;

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        string s; int val; cin >> s >> val;
        q.push(make_pair(val, s));
    }
    cout << q.top().second << endl;
}