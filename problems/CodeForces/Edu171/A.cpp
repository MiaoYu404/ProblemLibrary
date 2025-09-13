//Perpendicular Segments
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T; cin >> T;
    while(T--) {
        int X, Y, K; cin >> X >> Y >> K;
        int val = min(X, Y);
        cout << val << " " << val << " " << 0 << " " << 0 << endl;
        cout << 0 << " " << val << " " << val << " " << 0 << endl;
    }
    return 0;
}