#include <iostream>
using namespace std;

const int maxn = 2e5 + 10;
int n;
int a[maxn], b[maxn];

int main(){
    cin >> n;
    int ans = -2e15;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i == 1) b[i] = a[i];
        else b[i] = max(b[i - 1] + a[i], a[i]);
        ans = max(ans, b[i]);
    }
    cout << ans;
    return 0;
}