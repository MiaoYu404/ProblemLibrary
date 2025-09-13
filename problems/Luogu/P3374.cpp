#include <iostream>

using namespace std;

const int maxn = 5e5 + 10;
int c[maxn];
int n, m;

int lowbit (int x) {
    return x & -x;
}

int getsum (int x) {
    int ans = 0;
    while ( x > 0 ) {
        ans = ans + c[x];
        x = x - lowbit(x);
    }
    return ans;
}

void add (int x, int k) {
    while ( x <= n ) {
        c[x] = c[x] + k;
        x = x + lowbit(x);
    }
}

int main (){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        add(i, x);
    }

    while (m--) {
        int op; cin >> op;
        if(op == 1){
            int x, k; cin >> x >> k;
            add(x, k);
        }else {
            int x, y; cin >> x >> y;
            cout << getsum(y) - getsum(x - 1) << endl;
        }
    }

    return 0;
}