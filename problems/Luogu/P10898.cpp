#include <iostream>
#include <cmath>

using namespace std;

long long big = 7385137888721;
long long small = 10470245;

int main(){
    big += small / 4;
    int ans = sqrt(big) * 2;
    cout << ans;
}
