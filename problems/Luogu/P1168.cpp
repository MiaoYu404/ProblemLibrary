#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int> > p1;
    priority_queue<int, vector<int>, less<int> > p2;
    int ord = 1;
    for (int i = 1; i <= n; ++i, ++ord, ord %= 2) {
        int x; cin >> x;
        p1.push(x);
        if(p2.size())
        if (p1.top() < p2.top()) {
            int tmp = p1.top(); p1.pop();
            p1.push(p2.top());
            p2.pop();
            p2.push(tmp);
        }
        if (p2.size() < p1.size() - 1) {
            p2.push(p1.top()); p1.pop();
        }

        if (ord) {
            //if (p1.size() > p2.size())
            cout << p1.top() << '\n';
            //else cout << p2.top() << '\n';
        }
    }

    return 0;
}