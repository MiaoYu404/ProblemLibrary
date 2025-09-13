#include <iostream>
using namespace std;

long long x, a, b;

long long check(int x){
    if(x < 0) return x;
    if(a * x - b < x) return check(a * x - b);
    else return x;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> x >> a >> b;
        if(a == 1){
            if(b == 0){
                cout << x << endl;
                continue;
            }
            cout << x % b - b << endl;
            continue;
        }
        cout << check(x) << endl;
    }
    return 0;
}