#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        if(x < 5) {cout << -1 << endl; continue;}
        for (int i = 1; i <= x; i += 2){
            if(i == 5) continue;
            cout << i << " ";
        }
        cout << 5 << " " << 4 << " ";
        for (int i = 2; i <= x; i += 2) {
            if(i == 4) continue;
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}