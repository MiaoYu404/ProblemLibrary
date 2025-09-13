#include <bits/stdc++.h>
using namespace std;

int a, b, c, n;
vector<int> num;
queue<pair<int, int> > oper;
priority_queue<int, vector<int>, greater <int> > index[3];

void init() {
    a = 0; b = 0; c = 0;
    num.clear();
    while(!oper.empty()) oper.pop();
    while(!index[0].empty()) index[0].pop();
    while(!index[1].empty()) index[1].pop();
    while(!index[2].empty()) index[2].pop();
}

int find(int x) {
    int rsl = index[x].top();
    index[x].pop();
    return rsl;
    //for (int j =1;; j++) if (num[j] == x) {return j;}
}

void solve(int i) {
    int x = num[i];
    if (c != 0){
        if (x == 2) {c--; return;}
        if (x == 0) {
            int j = find(1);
            oper.push(make_pair(i, j));
            
            num[j] = 0; num[i] = 1;
        }
        int j = find(2); oper.push(make_pair(i, j));
        num[j] = 1; num[i] = 2;
        index[1].push(j);
        c--; return ;
    }

    if (b != 0) {
        if (x == 1) {b--; return;}
        int j = find(1); oper.push(make_pair(i, j));
        num[j] = 0; num[i] = 1; b--; return;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        init();
        cin >> n;
        num.push_back(-1);
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            num.push_back(x);
            if (x == 0) {a++;}
            else if (x == 1) {b++;}
            else c++;
            index[x].push(i);
        }

        for (int i = n; i >= 1; i--) {
            solve(i);
        }
        cout << oper.size() << endl;
        while(!oper.empty()) {
            pair<int, int> x = oper.front(); oper.pop();
            cout << x.first << " " << x.second << endl;
        }
    }
}