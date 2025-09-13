#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue< int, vector<int>, greater<int> > q;

int main(){
    int n; cin >> n;
    while(n--) {
        int op; cin >> op;
        if(op == 1){
            int x; cin >> x;
            q.push(x);
        }else if(op == 2) cout << q.top() << endl;
        else q.pop();
    }
}