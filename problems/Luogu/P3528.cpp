#include <iostream>
#include <queue>

using namespace std;

struct node{
    int color, length;
    bool operator < (const node &T) const{
        return length < T.length;
    }
};

priority_queue<node> q[55];
priority_queue<node> Q;

int main(){
    int k; cin >> k;
    for(int i = 1; i <= k; i++){
        int n; cin >> n;
        node max; max.length = 0;
        max.color = i;
        while(n--){
            node x; x.color = i;
            cin >> x.length;
            q[i].push(x);
            max = max < x ? x : max;
        }
        Q.push(max);
    }

    int ans = 0;

    while(!Q.empty()){
        node a = Q.top(); Q.pop();
        node b = Q.top(); Q.pop();
        node c = Q.top(); Q.pop();

        if(b.length + c.length >= a.length){
            cout << a.color << " " << a.length << " ";
            cout << b.color << " " << b.length << " ";
            cout << c.color << " " << c.length << " ";
            return 0;
        }
        else{
            Q.push(b), Q.push(c);
            int col = a.color; q[col].pop();
            if(!q[col].empty()){a = q[col].top(); Q.push(a);}
        }
        if(Q.size() < 3){
            cout << "NIE" << endl;
            return 0;
        }
    }
    return 0;
}