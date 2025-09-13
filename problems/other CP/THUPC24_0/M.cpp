#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int tt;

int main() {
    for (int i = 0; i <= 150; i++) {
        if (i % 3 == 2 and i % 5 == 3 and i % 7 == 6) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}