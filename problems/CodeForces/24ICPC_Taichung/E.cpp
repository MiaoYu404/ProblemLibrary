#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << 3 << endl;
    cout << b << " ";

    int x = -1e6, y = 1e6 + 3 * a - b;
    while (x <= b && y >= b && y > 1e6) {
        x += 1; y -= 1;
    }
    cout << x << " " << y << " " << endl;
}