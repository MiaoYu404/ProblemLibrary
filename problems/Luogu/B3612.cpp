#include <iostream>
using namespace std;

int a[100010];

int main(){
    int n, m; cin >> n;
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        a[i] = a[i - 1] + x;
    }
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        int l, r; cin >> l >> r;
        cout << a[r] - a[l - 1] << endl;
    }
}