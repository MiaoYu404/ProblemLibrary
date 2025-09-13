#include <bits/stdc++.h>
using namespace std;

bool visit[6];

int main() {
    for (int i = 1; i < 5; i++) {
        int x; cin >> x;
        visit[x] = true;
    }

    for (int i = 1; i <= 5; i++) {
        if(!visit[i]) cout << i << endl;
    }
}