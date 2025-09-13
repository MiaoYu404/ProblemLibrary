#include <bits/stdc++.h>
using namespace std;

struct info{
    int x, y, a, b;
};

stack<info> s;

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        info tmp;
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        tmp.x = x; tmp.y = y; tmp.a = a; tmp.b = b;
        s.push(tmp);
    }

    int x, y; cin >> x >> y;
    int ans = n;
    while(!s.empty()){
        info tmp = s.top();
        s.pop();

        if(x >= tmp.x && x <= tmp.x + tmp.a && y >= tmp.y && y <= tmp.y + tmp.b){
            cout << ans << endl;
            return 0; 
        }
        ans--;
    }
    cout << -1 << endl;
}