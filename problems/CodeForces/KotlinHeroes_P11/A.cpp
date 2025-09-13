//given x and y, output in acsending order
#include <bits\stdc++.h>
using namespace std;

int x, y;

int main(){
    int P;
    cin >> P;
    while(P--){
        cin >> x >> y;
        cout << min(x, y) << " " << max(x, y);
    }
    return 0;
}